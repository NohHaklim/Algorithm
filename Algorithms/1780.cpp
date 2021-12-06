#include <cstdio>

using namespace std;

int table[2200][2200];
int cnt[3];

int check(int n, int r, int c) {
	bool fail = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[r][c] != table[r + i][c + j]) {
				fail = true;
				break;
			}
		}
		if (fail == true) break;
	}
	if (fail == true) {
		return 2;
	}
	else return table[r][c];
}

void solve(int n, int r, int c) {
	int k = check(n, r, c);
	if (k != 2) {
		cnt[k + 1]++;
		return;
	}
	else {
		int mid = n / 3;
		solve(mid, r, c);
		solve(mid, r, c + mid);
		solve(mid, r, c + 2 * mid);

		solve(mid, r + mid, c);
		solve(mid, r + mid, c + mid);
		solve(mid, r + mid, c + 2 * mid);

		solve(mid, r + 2 * mid, c);
		solve(mid, r + 2 * mid, c + mid);
		solve(mid, r + 2 * mid, c + 2 * mid);
	}
	return;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &table[i][j]);
		}
	}

	solve(N, 0, 0);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", cnt[i]);
	}
}