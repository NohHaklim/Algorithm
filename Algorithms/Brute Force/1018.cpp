#include <cstdio>
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int N, M, res = 2600;
char table[50][50];

void check(int i, int j) {
	int change1 = 0, change2 = 0;
	
	for (int a = 0; a < 8; a += 2) {
		for (int b = 0; b < 8; b += 2) {
			if ('W' != table[i + a][j + b]) change1++;
			if ('W' == table[i + a][j + b + 1]) change1++;
			if ('W' == table[i + a + 1][j + b]) change1++;
			if ('W' != table[i + a + 1][j + b + 1]) change1++;

			if ('B' != table[i + a][j + b]) change2++;
			if ('B' == table[i + a][j + b + 1]) change2++;
			if ('B' == table[i + a + 1][j + b]) change2++;
			if ('B' != table[i + a + 1][j + b + 1]) change2++;
		}
	}
	change1 = min(change1, change2);
	res = min(res, change1);
}

int main() {
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			table[i][j] = getchar();
		}
		getchar();
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			check(i, j);
		}
	}

	printf("%d", res);
}