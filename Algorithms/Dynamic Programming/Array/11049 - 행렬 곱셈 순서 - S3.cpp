#include <cstdio>
#define MAX_SIZE 500 + 1
#define MIN_FUNC(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int N;
int DP[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &d[i - 1], &d[i]);
	}

	for (int diagonal = 1; diagonal <= N - 1; diagonal++) {
		for (int i = 1; i <= N - diagonal; i++) {
			int j = i + diagonal;
			int min = 0x7FFFFFFF;
			for (int k = i; k <= j - 1; k++) {
				min = MIN_FUNC(min,
					DP[i][k] + DP[k + 1][j] + d[i - 1] * d[k] * d[j]);
			}
			DP[i][j] = min;
		}
	}
	printf("%d", DP[1][N]);
}