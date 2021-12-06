#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

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

	int i = A.size() - 1, j = B.size() - 1, cnt = table[A.size() - 1][B.size() - 1];
	stack<char> s;
	cout << cnt << '\n';

	
	while (cnt) {
		if (i > 0 && j > 0 && A[i] == B[j]) {
			s.push(A[i]);
			cnt--;
			i--; j--;
		}
		else {
			if (i > 0 && table[i - 1][j] == table[i][j]) {
				i--;
			}
			else if (j > 0 && table[i][j - 1] == table[i][j]) {
				j--;
			}
		}
	}
	
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}