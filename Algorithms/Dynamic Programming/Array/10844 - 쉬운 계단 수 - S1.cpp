/*
	길이가 N인 계단수가 몇개인가?
	dp[x][j] = 길이가 x이고 그 길이의 수가 j일 때, 계단수의 갯수.

	dp[1] = 1 ~ 9 => 9개
	dp[2] =	10, 12
			21, 23
			32, 34
			43, 45 ...
			87, 89
			98
			=> 앞의 수가 0 or 9이면 1개 추가. 그렇지 않으면 2개 추가.
*/

#include <cstdio>
using namespace std;

int dp[101][10];

int main() {
	int number, sum = 0;
	scanf("%d", &number);

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= number; i++) {
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][0] = dp[i - 1][1] % 1000000000;
		dp[i][9] = dp[i - 1][8] % 1000000000;
	}

	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[number][i]) % 1000000000;
	}
	printf("%d", sum);
}