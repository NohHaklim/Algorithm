#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long llu;

const int MOD = 1000000007;

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
		a = ((this->element[0] * B.element[0]) % MOD
			+ (this->element[1] * B.element[2]) % MOD) % MOD;
		b = ((this->element[0] * B.element[1]) % MOD
			+ (this->element[1] * B.element[3]) % MOD) % MOD;
		c = ((this->element[2] * B.element[0]) % MOD
			+ (this->element[3] * B.element[2]) % MOD) % MOD;
		d = ((this->element[2] * B.element[1]) % MOD
			+ (this->element[3] * B.element[3]) % MOD) % MOD;
		return CMatrix(a, b, c, d);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	llu number;
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