/*
	���� x�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
	1. x�� 3���� ������ ��������, 3���� ������.
	2. x�� 2�� ������ ��������, 2�� ������.
	3. 1�� ����.
	���� Ƚ���� �ּ�ȭ�Ͽ� x�� 1�� ����ÿ�.
	
	dp[x]�� x�� ����� ������ Ƚ��
*/
#include <cstdio>
using namespace std;

int dp[1000001];

int solve(int x) {
	int tmp;
	if (x == 1) return 0;
	if (dp[x]) return dp[x];

	dp[x] = solve(x - 1) + 1;
	if (!(x % 2)) {
		tmp = solve(x / 2) + 1;
		if (dp[x] > tmp) dp[x] = tmp;
	}
	if (!(x % 3)) {
		tmp = solve(x / 3) + 1;
		if (dp[x] > tmp) dp[x] = tmp;
	}
	
	return dp[x];
}

int main() {
	int x, result;
	scanf("%d", &x);
	
	result = solve(x);
	printf("%d", result);
}