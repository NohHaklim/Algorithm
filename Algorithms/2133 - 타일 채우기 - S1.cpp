/*
	3 * N 타일에서
	1 * 2 와 2 * 1 타일로 타일링 한다?
	가로 길이는 2의 배수가 될 수 밖에 없네.
	각 배수별 추가되는 갯수 구해서 dp 해보자!
	(3의 배수로 타일링이 안됨)
*/

#include <cstdio>

typedef unsigned long long llu;
using namespace std;

llu dp[31];

int main() {
	int n;
	scanf("%d", &n);

	dp[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i] + dp[i - 2] * 3 + 2;
		for (int j = 4; j < i; j += 2) {
			dp[i] = dp[i] + dp[i - j] * 2;
		}
	}

	printf("%llu", dp[n]);
}