#include <iostream>
#include <vector>
using namespace std;

int N, K;
int Coins[11];

int solve(int k) {
	int i = N;
	int sum = 0;

	while (i >= 1 && k) {
		sum += k / Coins[i];
		k %= Coins[i];
		i--;
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> Coins[i];
	}

	cout << solve(K);
}