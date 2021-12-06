/*
	오르막 수를 구하자!
	전의 수와 같더라도 오르막 수이다!
	dp[x][j] = 길이 x일 때, 그 위치 숫자가 j이다. 이때의 오르막 수 갯수?
			 = dp[x - 1][0 ... j] 경우들의 합.
*/
#include <cstdio>
using namespace std;

int dp[1001][10];

int main() {
	int number, sum = 0;
	scanf("%d", &number);

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= number; i++) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[number][i]) % 10007;
	}
	printf("%d", sum);
}