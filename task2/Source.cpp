#include "matrix.h"
int main() {

	Matrix* matrix = read("input.txt");
	Element* maxelem = findMaxSpecificelement(matrix);
	print("output.txt", matrix, maxelem);
	return 0;
}