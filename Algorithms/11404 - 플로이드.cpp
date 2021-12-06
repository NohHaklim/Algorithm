#include <cstdio>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int table[101][101];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			table[i][j] = MAX;
		}
	}

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		
		table[from][to] = min(table[from][to], cost);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (table[i][j] == MAX) printf("0 ");
			else printf("%d ", table[i][j]);
		}
		printf("\n");
	}
}