#include <cstdio>

using namespace std;

bool table[128][128];

// 0: ÇÏ¾ç / 1: ÆÄ¶û

int cnt[2];

bool fail(int n, int r, int c) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[r][c] != table[r + i][c + j]) {
				return true;
			}
		}
	}
	return false;
}

void solve(int n, int r, int c) {
	if (n == 1) {
		if (table[r][c] == true) {
			cnt[1]++;
		}
		else {
			cnt[0]++;
		}
		return;
	}

	if (fail(n, r, c)) {
		int mid = n / 2;
		solve(mid, r, c);
		solve(mid, r, c + mid);
		solve(mid, r + mid, c);
		solve(mid, r + mid, c + mid);
	}
	else {
		cnt[table[r][c]]++;
	}
	
	return;
}

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			scanf("%d", &n);
			if (n == 1) table[i][j] = true;
			else table[i][j] = false;
		}
	}

	solve(N, 0, 0);

	printf("%d\n%d", cnt[0], cnt[1]);
}