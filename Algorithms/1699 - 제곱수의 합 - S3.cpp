#include <cstdio>
#define MAX 100000 + 1
#define MIN_FUNC(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int N;
int DP[MAX] = { 0, 1, 2, 3, 1, 2, 3, 4, 2, 1 };

int solve(int n) {
	if (DP[n] != -1) return DP[n];

	int temp = MAX;
	for (int i = 1; i * i <= n; i++) {
		temp = MIN_FUNC(temp, solve(n - (i * i)) + 1);
	}
	DP[n] = temp;
	return DP[n];
}

int main() {
	scanf("%d", &N);
	for (int i = 8; i < MAX; i++) {
		DP[i] = -1;
	}

	for (int i = 1; i <= N; i++) {
		solve(i);
	}
	
	printf("%d\n", DP[N]);
}