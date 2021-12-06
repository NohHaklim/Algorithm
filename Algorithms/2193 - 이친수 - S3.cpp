/*
	1. 이친수는 0으로 시작하지 않는다.
	2. 이친수에서는 1이 두 번 연속으로 나타나지 않는다.

	x자리 이친수의 갯수를 구하라?
	dp[x][j] = x자리가 j인 이친수의 갯수.
	
	dp[x][1] = dp[x - 1][0]
	dp[x][0] = dp[x - 1][0] + dp[x - 1][1]
*/

#include <cstdio>

typedef unsigned long long llu;
using namespace std;

llu dp[91][2];

int main() {
	llu x, res = 0;
	scanf("%llu", &x);
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (llu i = 2; i <= x; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	res = dp[x][0] + dp[x][1];
	printf("%llu", res);
}