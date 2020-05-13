#include "menu.h"

using namespace std;

void callMenu() {
	cout << "введите 0 - для перезаписи информации\n\
введите 1 - для показа информации о введенной матрицу;\n\
введите 2 - для нахождения значение максимального элемента матрицы\n\
среди всех элементов тех строк матрицы, которые упорядоченых;\n\
введите 3 - для пока результатов;\nиначе программа будет завершнена\n";
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
	cout << "введенный текст...\n";
	cout << echo("input.txt");
	cout << "\n";
}
void showOutput() {
	cout << "результат...\n";
	cout << echo("output.txt");
	cout << "\n";
}
void recodInput() {
	cout << "введите n и m - размерность матрицы\n";
	Matrix* matrix = new Matrix;
	cin >> matrix->n >> matrix->m;
	cout << "введите " << matrix->n * matrix->m << " елементов\n";
	matrix->values = new double[matrix->n * matrix->m];
	for (int i = 0; i < matrix->n; i++) {
		for (int j = 0; j < matrix->m; j++) {
			cin >> *(matrix->values + i * matrix->m + j);
		}
	}
	print("input.txt", false, matrix, NULL);
	cout << "\nперезапись выполнена успешно";
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