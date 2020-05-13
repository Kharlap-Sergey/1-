#include "menu.h"

using namespace std;

void callMenu() {
	cout << "������� 0 - ��� ���������� ����������\n\
������� 1 - ��� ������ ���������� � ��������� �������;\n\
������� 2 - ��� ���������� �������� ������������� �������� �������\n\
����� ���� ��������� ��� ����� �������, ������� ������������;\n\
������� 3 - ��� ���� �����������;\n����� ��������� ����� ����������\n";
	cout << "-------------------------------------------\n";
	int t = 0;
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
	case 2: {
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
	cout << "��������� �����...\n";
	cout << echo("input.txt");
	cout << "\n";
}
void showOutput() {
	cout << "���������...\n";
	cout << echo("output.txt");
	cout << "\n";
}
void recodInput() {
	cout << "������� n � m - ����������� �������\n";
	Matrix* matrix = new Matrix;
	cin >> matrix->n >> matrix->m;
	cout << "������� " << matrix->n * matrix->m << " ���������\n";
	matrix->values = new double[matrix->n * matrix->m];
	for (int i = 0; i < matrix->n; i++) {
		for (int j = 0; j < matrix->m; j++) {
			cin >> *(matrix->values + i * matrix->m + j);
		}
	}
	print("input.txt", false, matrix, NULL);
	cout << "\n���������� ��������� �������";
}


void calculateAnswer() {
	Matrix* matrix = read("input.txt");
	Element* maxelem = findMaxSpecificelement(matrix);
	print("output.txt", true, matrix, maxelem);
}

void setrus() {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");
}

char* echo(const char* file) {
	char* text = new char[10000];
	ifstream in;
	in.open(file);
	in.get(text, 10000, '/');
	in.close();
	return text;
}