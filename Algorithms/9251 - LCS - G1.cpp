#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int table[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string A, B;
	cin >> A >> B;

	A = '\0' + A;
	B = '\0' + B;
	for (int i = 1; i < A.size(); i++) {
		for (int j = 1; j < B.size(); j++) {
			int res = max(table[i - 1][j], table[i][j - 1]);
			if (A[i] == B[j]) res = max(res, table[i - 1][j - 1] + 1);
			table[i][j] = res;
		}
	}

	printf("%d", table[A.size() - 1][B.size() - 1]);
}