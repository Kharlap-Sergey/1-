#include "matrix.h"
Matrix* read(const char* filename) {
	Matrix* matr = new Matrix;

	ifstream in;
	in.open(filename);
	in >> matr->n;
	in >> matr->m;
	double* mass = new double[matr->n * matr->m + 1];
	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			in >> *(mass + i * matr->m + j);
		}
	}
	in.close();

	matr->values = mass;
	return matr;
}

bool isRowIncrease(Matrix* matr, int rwoNumber, int rowLength) {
	bool ans = true;
	for (int i = 0; i < rowLength - 1; i++) {
		if (*(matr->values + rwoNumber * rowLength + i) > *(matr->values + rwoNumber * rowLength + i + 1)) {
			ans = false;
			break;
		}
	}
	return ans;
}

bool isRowDecrease(Matrix* matr, int rwoNumber, int rowLength) {
	bool ans = true;
	for (int i = 0; i < rowLength - 1; i++) {
		if (*(matr->values + rwoNumber * rowLength + i) < *(matr->values + rwoNumber * rowLength + i + 1)) {
			ans = false;
			break;
		}
	}
	return ans;
}
bool isRowOdered(Matrix* matr, int rwoNumber, int rowLength) {
	return isRowDecrease(matr, rwoNumber, rowLength) || isRowIncrease(matr, rwoNumber, rowLength);
}

void print(const char* filename, Matrix* matr, Element* elem) {
	fstream out;
	out.open(filename);
	out << matr->n << ' ';
	out << matr->m << endl;;
	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			out << *(matr->values + i * matr->m + j) << ' ';
		}
		out << endl;
	}
	out << "max element - " << elem->value << "\nid " << elem->n << ' ' << elem->m << endl;
	out.close();
}

Element* findMaxSpecificelement(Matrix* matr) {
	Element* element = new Element;

	element->value = -1111111111;
	for (int i = 0; i <= matr->n; i++) {
		double mx = -1111111111;
		int jj = 0;
		if (isRowOdered(matr, i, matr->m)) {
			for (int j = 0; j < matr->m; j++) {
				if (mx < *(matr->values + i * matr->m + j)) {
					mx = *(matr->values + i * matr->m + j);
					jj = j;
				}
			}
			if (element->value < mx) {
				element->n = i;
				element->m = jj;
				element->value = mx;
			}
		}
	}
	return element;
}
