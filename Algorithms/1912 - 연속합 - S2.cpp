/*
	dp[i] = i번 째 수열까지 합 중 가장 큰 합.
	dp[i] = max(dp[i - 1] + arr[i], arr[i])
*/

#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int arr[100000];
int dp[100000];

int main() {
	int n, res;
	scanf("%d", &n);
	
	scanf("%d", &arr[0]);
	dp[0] = arr[0];
	res = dp[0];

	for (int i = 1; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		res = max(res, dp[i]);
	}

	printf("%d", res);
}