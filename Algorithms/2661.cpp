#include <iostream>
#include <string>
using namespace std;

int N;
string num;

void permutation(char c, int idx) {
	if (idx - 1 == N) {
		cout << num;
		exit(0);
	}

	num += c;
	for (int i = 1; i <= idx / 2; i++) {
		string a = num.substr(idx - i * 2, i);
		string b = num.substr(idx - i, i);
		//cout << "base: " << num << "\t\t\ta: " << a << "\t\t\tb: " << b << "\n";

		if (a == b) {
			num.erase(idx - 1);
			return;
		}
	}

	for (int i = 1; i <= 3; i++)
		permutation(i + '0', idx + 1);
	num.erase(idx - 1); // 백트래킹
	return;
}

int main() {
	cin >> N;
	for (int i = 1; i <= 3; i++)
		permutation(i + '0', 1);
}