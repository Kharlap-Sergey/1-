#include <iostream>
#include <fstream>
#include "mylib.h"

using namespace std;

ifstream in;
ofstream out;
char* read(const char* filename) {
	in.open(filename);
	char* pointer = new char[TextMaxLen];
	in.get(pointer, TextMaxLen-10, '/');
	in.close();
	return pointer;
}
bool isAlpha(char c) {
	bool ans = 'А' <= c && c <= 'я';
	return ans;
}

bool isEndSign(char c) {
	return c == '.' || c == '?' || c == '!';
}
void separateText(char* text, SeparatedText* sent) {
	char* boof = new char[LineMaxLen];
	int boofc = 0;
	bool IsSentenseStarted = false;
	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] == '/' or text[i] == '\n') continue;

		if (isEndSign(text[i]) && !isEndSign(text[i+1]) && boofc != 0) {
			boof[boofc] = text[i];
			boof[boofc + 1] = '\0';
			sent->sentences[sent->sentencesNumber].value = boof;
			sent->sentences[sent->sentencesNumber].len = boofc + 2;
			sent->sentencesNumber++;
			boof = new char[LineMaxLen];
			boofc = 0;
			IsSentenseStarted = false;
			continue;
		}

		IsSentenseStarted = isAlpha(text[i]) || IsSentenseStarted;
		if (IsSentenseStarted) {
			boof[boofc] = text[i];
			boofc++;
		}
	}
}

int calculateComplexity(Sentences* pattern) {
	int complexity = 0;
	bool IsWordStarted = false;
	for (int i = 0; pattern->value[i] != '\0'; i++) {
		if (isAlpha(pattern->value[i])) {
			if (!IsWordStarted) complexity++;
			IsWordStarted = true;
		}
		else {
			IsWordStarted = false;
			if (isEndSign(pattern->value[i]) && isEndSign(pattern->value[i + 1]))continue;
			if (pattern->value[i] != ' ' and pattern->value[i] != '\n') complexity++;
		}
		//cout << pattern->value[i] << complexity << endl;
	}

	return complexity;
}

void analyseSentenses(SeparatedText* sep) {
	for (int i = 0; i < sep->sentencesNumber; i++) {
		sep->sentences[i].complexity = calculateComplexity(sep->sentences + i);
	}
}

double calculateAverageComplexity(SeparatedText* sep) {
	double complexitySum = 0;

	for (int i = 0; i < sep->sentencesNumber; i++) {
		complexitySum += sep->sentences[i].complexity;
	}

	return complexitySum / sep->sentencesNumber;
}

Sentences* findSentenceWithMaxComplexity(SeparatedText* sep) {
	Sentences *ans = new Sentences;
	ans = sep->sentences;
	for (int i = 0; i < sep->sentencesNumber; i++) {
		if(ans->complexity < sep->sentences[i].complexity)
			ans = sep->sentences+i;
	}

	return ans;
}
void print(const char* OUT, char* text, double averageComplexity, Sentences* sentenceWithMaxComplexity){
	out.open(OUT);

	out << text << endl;
	out << "средняя сложность текста - " << averageComplexity << endl;
	void print(const char* OUT, char* text, double averageComplexity, Sentences * sentenceWithMaxComplexity);	
	out << "предложение с максимальной сложностью:\n" << sentenceWithMaxComplexity->value << " ---- " << sentenceWithMaxComplexity->complexity;
	out.close();
}