/*
	dp[x][j] = x열에서
				j = 0: 스티커 안뗌
				  = 1: 1번 스티커 사용
				  = 2: 2번 스티커 사용 했을 경우 최대 점수.
	dp[x][0] = max(dp[x - 1][0], dp[x - 1][1], dp[x - 1][2])
	dp[x][1] = max(dp[x - 1][0], dp[x - 1][2]) + 1번 스티커 점수
	dp[x][2] = max(dp[x - 1][0], dp[x - 1][1]) + 2번 스티커 점수
	
	그리고 dp[x][0...2] 값 중 최댓값을 고른다.
*/

#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int table[2][100001];
int dp[100001][3];

int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int x;
		scanf("%d", &x);
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= x; j++) {
				scanf("%d", &table[i][j]);
			}
		}

		dp[1][0] = 0;
		dp[1][1] = table[0][1];
		dp[1][2] = table[1][1];
		for (int i = 1; i <= x; i++) {
			dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + table[0][i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + table[1][i];
		}

		printf("%d\n", max(max(dp[x][0], dp[x][1]), dp[x][2]));
	}
}