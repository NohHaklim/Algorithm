/*
	1개의 testcase에 나올 수 있는 수의 최대 갯수가 100개인데,
	모든 쌍에 대해서 GCD를 찾는다면, 10C2 = 4950이 나온다.
	그런데 수의 최댓값이 1,000,000이므로,
	모든 수가 1,000,000이 나올 경우, 정답이 가능한 수는 4,950,000,000이므로
	long long형에 sum값을 기록해야 한다.
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