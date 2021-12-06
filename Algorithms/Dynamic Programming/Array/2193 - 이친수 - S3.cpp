/*
	1. ��ģ���� 0���� �������� �ʴ´�.
	2. ��ģ�������� 1�� �� �� �������� ��Ÿ���� �ʴ´�.

	x�ڸ� ��ģ���� ������ ���϶�?
	dp[x][j] = x�ڸ��� j�� ��ģ���� ����.
	
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