/*
	3 * N Ÿ�Ͽ���
	1 * 2 �� 2 * 1 Ÿ�Ϸ� Ÿ�ϸ� �Ѵ�?
	���� ���̴� 2�� ����� �� �� �ۿ� ����.
	�� ����� �߰��Ǵ� ���� ���ؼ� dp �غ���!
	(3�� ����� Ÿ�ϸ��� �ȵ�)
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