/*
	어떤 수 x를 1, 2, 3의 합으로 표현하는 방법의 수를 알아보자.
	dp[x] = 어떤 수 x를 1, 2, 3의 합으로 표현하는 방법의 수.
	dp[x] = dp[x - 1] + dp[x - 2] + dp[x - 3];
*/
#include <cstdio>
using namespace std;

int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int number, dp[12] = { 0 };
		scanf("%d", &number);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= number; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		printf("%d\n", dp[number]);
	}
}