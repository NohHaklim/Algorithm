/*
	사람들 계산식이 나랑 좀 다르던데.
	같은 문제 푼 거 맞나...?
*/
#include <cstdio>
using namespace std;

int main() {
	int testcase;
	long long DP[10001] = { 0 };
	scanf("%d", &testcase);

	DP[1] = 0;
	DP[2] = 0;
	DP[3] = 3;
	DP[6] = 13;
	while (testcase--) {
		int N;
		scanf("%d", &N);
		for (int i = 9; i <= N; i += 3) {
			DP[i] = (DP[i - 3] * 3) % 1000000007;
			int j;
			for (j = 2; 3 * j < i; j++) {
				DP[i] = (DP[i] + (DP[i - (3 * j)] * (j * 2))) % 1000000007;
			}
			DP[i] = (DP[i] + (j * 2)) % 1000000007;
		}
		printf("%d\n", DP[N]);
	}
}