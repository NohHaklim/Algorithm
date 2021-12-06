#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b)) 
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int n, res = 0;
	scanf("%d", &n);
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;
		res = max(dp[i], res);
	}
	
	printf("%d\n", res);
}