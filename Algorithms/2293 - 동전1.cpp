#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	int coins[100] = { 0 };
	int dp[10001] = { 1 };

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	// dp[k] = k원을 만드는 경우의 수
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	cout << dp[k];
}