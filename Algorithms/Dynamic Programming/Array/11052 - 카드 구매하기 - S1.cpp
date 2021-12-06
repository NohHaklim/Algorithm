/*
	dp[i]: i번 째 카드팩까지 사용했을 때의 최대 가격

	dp[1]:	p1
	dp[2]:	max(dp[1] + p1, p2)
	dp[3]:	max(dp[2] + p1, dp[1] + p2, p3)
	
**/


#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int p[1001];
int dp[1001];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);

	dp[1] = p[1];
	for (int i = 2; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j < i; j++) {
			temp = max(temp, dp[j] + p[i - j]);
		}
		temp = max(temp, p[i]);
		dp[i] = temp;
	}

	printf("%d\n", dp[n]);
}