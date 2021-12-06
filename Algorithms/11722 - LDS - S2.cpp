#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int dp[1000];
int arr[1000];

int main() {
	int n, res = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		
		int temp = 0;
		for (int j = 0; j < i; j++) {	
			if (arr[j] > arr[i]) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;
		res = max(res, dp[i]);
	}

	printf("%d\n", res);
}