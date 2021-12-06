#include <cstdio>
using namespace std;

bool table[3100][6200];

void solve(int n, int r, int c) {
	if (n == 3) {
		table[r][c + 2] = true;
		table[r + 1][c + 1] = true;
		table[r + 1][c + 3] = true;
		for (int i = 0; i < 5; i++) {
			table[r + 2][c + i] = true;
		}
		return;
	}

	int mid = n / 2;
	solve(mid, r, c + mid);
	solve(mid, r + mid, c);
	solve(mid, r + mid, c + 2 * mid);
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	solve(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (table[i][j] == true) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}