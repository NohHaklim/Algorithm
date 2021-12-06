#include <cstdio>

using namespace std;

bool table[2200][2200];

void solve(int n, int r, int c) {
	if (n == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1);
				else {
					table[r + i][c + j] = true;
				}
			}
		}
		return;
	}
	
	int mid = n / 3;
	solve(mid, r, c);
	solve(mid, r, c + mid);
	solve(mid, r, c + 2 * mid);

	solve(mid, r + mid, c);
	solve(mid, r + mid, c + 2 * mid);

	solve(mid, r + 2 * mid, c);
	solve(mid, r + 2 * mid, c + mid);
	solve(mid, r + 2 * mid, c + 2 * mid);
	return;
}

int main() {
	int N;
	scanf("%d", &N);

	solve(N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}