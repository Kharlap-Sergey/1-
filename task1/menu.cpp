#include "menu.h"

using namespace std;

void callMenu() {
	cout << "������� 0 - ��� ���������� ����������\n\
������� 1 - ��� ������ ���������� � ��������� �������;\n\
������� 2 - ��� �������� ������� ��������� ������, � ���������� ����������� � ������������ ����������;\n\
������� 3 - ��� ���� �����������;\n����� ��������� ����� ����������\n";
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
		cout << "����� ��������\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 3: {
		showOutput();
		cout << "-------------------------------------------\n";
		break;
	}
	default: {
		cout << "����������!!!";
		return;
	}
	}

	callMenu();
}
void showInput() {
	char* text = read(IN);
	cout << "��������� �����...\n";
	cout << text << endl;
}
void showOutput() {
	char* text = read(OUT);
	cout << "���������...\n";
	cout << text << endl;
}
void recodInput() {
	cout << "������� ����� �� ������ ����� ��������������� �������� '/'\n";
	char* text = new char[TextMaxLen];
	cin.get(text, TextMaxLen - 10, '/');
	cout << text;
	cin.get();
	print(IN, text, false, 0, NULL);
	cout << "\n���������� ��������� �������";
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
