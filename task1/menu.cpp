#include "menu.h"

using namespace std;

void callMenu() {
	cout << "введите 0 - для перезаписи информации\n\
введите 1 - для показа информации о введенном тексете;\n\
введите 2 - для подсчета средней сложности тестка, и нахождения предложения с максимальной сложностью;\n\
введите 3 - для пока результатов;\nиначе программа будет завершнена\n";
	cout << "-------------------------------------------\n";
	int t ;
	cin >> t;
	switch (t) {
	case 0: {
		recodInput();
		cout << "-------------------------------------------\n";
		break;
	}
	case 1: {
		showInput();
		cout << "-------------------------------------------\n";
		break;
	}
	case 2:{
		calculateAnswer();
		cout << "ответ посчитан\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 3: {
		showOutput();
		cout << "-------------------------------------------\n";
		break;
	}
	default: {
		cout << "Досвидания!!!";
		return;
	}
	}

	callMenu();
}
void showInput() {
	char* text = read(IN);
	cout << "введенный текст...\n";
	cout << text << endl;
}
void showOutput() {
	char* text = read(OUT);
	cout << "результат...\n";
	cout << text << endl;
}
void recodInput() {
	cout << "введите текст на руском языке заканчивающийся символом '/'\n";
	char* text = new char[TextMaxLen];
	cin.get(text, TextMaxLen - 10, '/');
	cout << text;
	cin.get();
	print(IN, text, false, 0, NULL);
	cout << "\nперезапись выполнена успешно";
}
void calculateAnswer() {
	char* text;
	SeparatedText sent;
	text = read(IN);
	separateText(text, &sent);
	analyseSentenses(&sent);
	double averageComplexity = calculateAverageComplexity(&sent);
	Sentences* sentenceWithMaxComplexity = findSentenceWithMaxComplexity(&sent);
	print(OUT, text, true, averageComplexity, sentenceWithMaxComplexity);
}
