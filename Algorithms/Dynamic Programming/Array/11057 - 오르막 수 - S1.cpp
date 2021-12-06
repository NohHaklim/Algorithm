/*
	������ ���� ������!
	���� ���� ������ ������ ���̴�!
	dp[x][j] = ���� x�� ��, �� ��ġ ���ڰ� j�̴�. �̶��� ������ �� ����?
			 = dp[x - 1][0 ... j] ������ ��.
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