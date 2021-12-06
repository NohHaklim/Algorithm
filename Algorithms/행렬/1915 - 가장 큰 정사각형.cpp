#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char table[1001][1001];
int dp[1001][1001];
int ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> table[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (table[i][j] == '1') {
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				dp[i][j]++;
				if (ret < dp[i][j])
					ret = dp[i][j];
			}
		}
	}
	cout << ret * ret;
}