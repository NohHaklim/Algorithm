#include <iostream>
#include <string>

using namespace std;

bool image[64][64];

string solve(int n, int i, int j) {
	if (n == 1) {
		if (image[i][j]) return "1";
		else return "0";
	}

	int mid = n / 2;
	string a = solve(mid, i, j);
	string b = solve(mid, i, j + mid);
	string c = solve(mid, i + mid, j);
	string d = solve(mid, i + mid, j + mid);

	if (a == b && b == c && c == d && a.length() == 1) {
		return a;
	}
	else {
		return "(" + a + b + c + d + ")";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			if (c == '1') image[i][j] = true;
		}
	}

	string ans = solve(N, 0, 0);

	cout << ans;
}