#include <fstream>
using namespace std;

struct Matrix {
	int n, m; // размерность матрицы
	double* values; // ссылка на элементы матрицы 
};

struct Element { 
	int n, m; // индексы элемента
	double value; // значение элемента
};

Matrix* read(const char* filename); // функция, читабщая матрицу из файла.
void print(const char* filename, Matrix* matr, Element* elem); // функция, выводящая ответ.
Element* findMaxSpecificelement(Matrix* matr); // функция, находящая максимальный элемент среди всех упопрядоченных рядов.