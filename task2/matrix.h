#include <fstream>
using namespace std;

struct Matrix {
	int n, m; // ����������� �������
	double* values; // ������ �� �������� ������� 
};

struct Element { 
	int n, m; // ������� ��������
	double value; // �������� ��������
};

Matrix* read(const char* filename); // �������, �������� ������� �� �����.
void print(const char* filename, Matrix* matr, Element* elem); // �������, ��������� �����.
Element* findMaxSpecificelement(Matrix* matr); // �������, ��������� ������������ ������� ����� ���� �������������� �����.