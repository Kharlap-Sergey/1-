#include "variabels.h"
#include <iostream>
#include <fstream>
char* read(const char* filename); // �������, �������� ����� �� �����.
void separateText(char* text, SeparatedText* sent); // �������, ����������� ����� �� �����������.
void analyseSentenses(SeparatedText* sep);// �������, ����������� ��������� �����������.
double calculateAverageComplexity(SeparatedText* sep);// �������, ����������� ������� ��������� �����.
Sentences* findSentenceWithMaxComplexity(SeparatedText* sep);// ������� ��������� ����������� � ������������ ����������
void print(const char* OUT, char* text, bool f, double averageComplexity, \
	Sentences* sentenceWithMaxComplexity); // �������, ��������� ����� � ����.
void setrus(); // �������� �������, �������� ����������� ����������.