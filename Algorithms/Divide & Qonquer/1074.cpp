#include <iostream>
#include <cmath>

using namespace std;

int N, R, C;
int ans = 0;

void solve(int n, int r, int c) {
	if (n == 2) {
		if (r == R && c == C) {
			cout << ans;
			return;
		}
		ans++;
		if (r == R && c + 1 == C) {
			cout << ans;
			return;
		}
		ans++;
		if (r + 1 == R && c == C) {
			cout << ans;
			return;
		}
		ans++;
		if (r + 1 == R && c + 1 == C) {
			cout << ans;
			return;
		}
		ans++;
		return;
	}

	int mid = n / 2;
	if (r <= R && R < r + n && c <= C && C < c + n) {
		solve(mid, r, c);
		solve(mid, r, c + n / 2);
		solve(mid, r + n / 2, c);
		solve(mid, r + n / 2, c + n / 2);
	}
	else ans += n * n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R >> C;
	solve(1 << N, 0, 0);
}