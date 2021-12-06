#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int arr[1000];
int dp1[1000], dp2[1000];

int main() {
	int n, ret = 0;
	scanf("%d", &n);

	
	for (int i = 0; i < n; i++) {
		int temp = 0;
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				temp = max(temp, dp1[j]);
			}
		}
		dp1[i] = temp + 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		int temp = 0;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				temp = max(temp, dp2[j]);
			}
		}
		dp2[i] = temp + 1;
		ret = max(dp1[i] + dp2[i], ret);
	}
	printf("%d", ret - 1);
}