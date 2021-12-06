#include <iostream>
#include <string>

using namespace std;
typedef unsigned long long llu;

int main() {
	int L;
	cin >> L;

	string str;
	cin >> str;

	int M = 1234567891;
	llu sum = 0, r = 1;
	for (int i = 0; i < L; i++) {
		llu k = ((str[i] - 'a' + 1) * r) % M;
		sum = (sum + k) % M;
		r = (r * 31) % M;
	}
	printf("%llu", sum);
}