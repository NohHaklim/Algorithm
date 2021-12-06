#include <iostream>
#include <string>

using namespace std;

int main() {
	string A, B, res;
	cin >> A >> B;
	
	if (A[0] == '0') {
		int i;
		for (i = 1; i < A.size(); i++) {
			if (A[i] != '0') break;
		}
		if (A.size() == i) {
			A = '0';
		}
		else {
			A = A.substr(i);
		}
	}

	if (B[0] == '0') {
		int i;
		for (i = 1; i < B.size(); i++) {
			if (B[i] != '0') break;
		}
		if (B.size() == i) {
			B = '0';
		}
		else {
			B = B.substr(i);
		}
	}

	int A_len, B_len, res_len;
	A_len = A.size();
	B_len = B.size();
	res_len = (A_len < B_len ? B_len : A_len);
	A_len--; B_len--;

	bool carry = false;
	while (A_len >= 0 || B_len >= 0) {
		int s = 0;
		if (A_len >= 0) {
			s = s + A[A_len] - '0';
			A_len--;
		}
		if (B_len >= 0) {
			s = s + B[B_len] - '0';
			B_len--;
		}

		if (carry) {
			s++;
			carry = false;
		}
		if (s >= 2) {
			carry = true;
			s -= 2;
		}
		
		res = (char)(s + '0') + res;
	}

	if (carry) {
		res = '1' + res;
	}

	cout << res;
}