#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int arr[1000];
int dp[1000];

int main() {
	int n, ret = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				temp = max(temp, dp[j]);
			}
		}
		
		dp[i] = temp + arr[i];
		ret = max(ret, dp[i]);
	}
	printf("%d", ret);
}