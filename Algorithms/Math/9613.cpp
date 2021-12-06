/*
	1���� testcase�� ���� �� �ִ� ���� �ִ� ������ 100���ε�,
	��� �ֿ� ���ؼ� GCD�� ã�´ٸ�, 10C2 = 4950�� ���´�.
	�׷��� ���� �ִ��� 1,000,000�̹Ƿ�,
	��� ���� 1,000,000�� ���� ���, ������ ������ ���� 4,950,000,000�̹Ƿ�
	long long���� sum���� ����ؾ� �Ѵ�.
*/
#include <cstdio>
using namespace std;

int arr[101];

int gcd(int a, int b) {
	while (true) {
		int r = a % b;
		if (r == 0) break;
		a = b;
		b = r;
	}
	return b;
}

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		int n;
		long long sum = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);

		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				sum += gcd(arr[i], arr[j]);
		printf("%ld\n", sum);
	}
}