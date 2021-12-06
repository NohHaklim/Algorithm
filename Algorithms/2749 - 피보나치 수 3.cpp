/*
	피보나치 수열의 정의
	F[i + 1] = F[i] + F[i - 1]
	F[i] = F[i] + 0
	를 행렬식으로 바꾸면...

	(F[i + 1])	(1 1) (  F[i]  )
	(  F[i]	 )	(1 0) (F[i - 1])

	=> (1 1)^i (1)
	   (1 0)   (0)

*/
#include <iostream>

using namespace std;
typedef unsigned long long llu;

class CMatrix {
public:
	llu element[4];

	CMatrix(llu a, llu b, llu c, llu d) {
		element[0] = a;
		element[1] = b;
		element[2] = c;
		element[3] = d;
	}

	CMatrix operator * (CMatrix B) {
		llu a, b, c, d;
		a = (this->element[0] * B.element[0] + this->element[1] * B.element[2]) % 1000000;
		b = (this->element[0] * B.element[1] + this->element[1] * B.element[3]) % 1000000;
		c = (this->element[2] * B.element[0] + this->element[3] * B.element[2]) % 1000000;
		d = (this->element[2] * B.element[1] + this->element[3] * B.element[3]) % 1000000;
		return CMatrix(a, b, c, d);
	}
};

int main() {
	int number;
	cin >> number;
	CMatrix pibo(1, 0, 0, 1), base(1, 1, 1, 0);
	if (number < 2) {
		cout << number;
		return 0;
	}
	while (number) {
		if (number & 1) {
			pibo = pibo * base;
		}
		base = base * base;
		number >>= 1;
	}
	cout << pibo.element[1];
}