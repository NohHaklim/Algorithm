#include <cstdio>
using namespace std;

class Matrix {
private:
	int _sz;
	int **matrix;
public:
	Matrix(int n) {
		_sz = n;
		matrix = new int*[n];
		for (int i = 0; i < n; i++)
			matrix[i] = new int[n];

		for (int i = 0; i < _sz; i++)
			for (int j = 0; j < _sz; j++)
				matrix[i][j] = 0;
	}
	~Matrix() {
		for (int i = 0; i < _sz; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	Matrix& operator * (Matrix &operand) {
		Matrix *ret = new Matrix(_sz);
		
		for (int i = 0; i < _sz; i++)
			for (int j = 0; j < _sz; j++)
				for (int k = 0; k < _sz; k++){
					ret->matrix[i][j] += matrix[i][k] * operand.matrix[k][j];
					ret->matrix[i][j] %= 1000;
				}
		return *ret;
	}
	Matrix& operator = (const Matrix &operand) {
		_sz = operand._sz;
		for (int i = 0; i < _sz; i++)
			for (int j = 0; j < _sz; j++)
				matrix[i][j] = operand.matrix[i][j];
		return *this;
	}
	void print() {
		for (int i = 0; i < _sz; i++) {
			for (int j = 0; j < _sz; j++) {
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
	}
	void scan() {
		for (int i = 0; i < _sz; i++)
			for (int j = 0; j < _sz; j++)
				scanf("%d", &matrix[i][j]);
	}
	void convert_to_Identity() {
		for (int i = 0; i < _sz; i++)
			for (int j = 0; j < _sz; j++)
				if (i == j) matrix[i][j] = 1;
	}
};

int main() {
	int A;
	long long B;
	scanf("%d %lld", &A, &B);
	Matrix M(A);
	M.scan();
	
	Matrix ret(A);
	ret.convert_to_Identity();

	if (B & 1) {
		ret = ret * M;
	}
	B >>= 1;
	while (B > 0) {
		M = M * M;
		if (B & 1) {
			ret = ret * M;
		}
		B >>= 1;
	}
	ret.print();
}