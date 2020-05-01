#include <iostream>
#include <fstream>
#include "mylib.h"

using namespace std;

char* text;

SeparatedText sent;


int main() {
	setlocale(LC_ALL, "rus");
	text = read(IN);
	separateText(text, &sent);
	analyseSentenses(&sent);
	
	double averageComplexity = calculateAverageComplexity(&sent);
	Sentences* sentenceWithMaxComplexity = findSentenceWithMaxComplexity(&sent);

	print(OUT, text, averageComplexity, sentenceWithMaxComplexity);
	return 0;
}