/*
	1. 포토주 잔을 선택하면 => 모두 마신 후, 원래 자리
	2. 연속으로 놓여있는 3잔을 모두 마실 수 없다.
	전제 조건. 포도주는 마시거나 마시지 않거나.

	포도주를 가장 많이 마실 수 있는 경우?
	dp[i][j][k] = i 번째 포도주를 j(마시거나 안마시거나) k(현재까지 연속된 수)

	dp[i][0][0] = max(dp[i - 1][1][1], dp[i - 1][1][2], dp[i - 1][0][0])
	dp[i][1][1] = dp[i - 1][0][0] + i번째 포도주 양
	dp[i][1][2] = dp[i - 1][1][1] + i번째 포도주 양
*/

#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int l[10001];
int dp[10001][2][3];

int main() {
	int x;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++) {
		scanf("%d", &l[i]);
	}

	dp[1][1][1] = l[1];
	for (int i = 2; i <= x; i++) {
		dp[i][0][0] = max(max(dp[i - 1][1][1], dp[i - 1][1][2]), dp[i - 1][0][0]);
		dp[i][1][1] = dp[i - 1][0][0] + l[i];
		dp[i][1][2] = dp[i - 1][1][1] + l[i];
	}

	printf("%d\n", max(max(dp[x][0][0], dp[x][1][1]), dp[x][1][2]));
}