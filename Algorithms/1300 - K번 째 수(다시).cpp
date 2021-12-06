#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	int left = 1, right = k, ans = -1;
	while (left <= right) {
		lld cnt = 0;
		int mid = (left + right) / 2;
		for (int i = 1; i <= n; i++)
			cnt += min(mid / i, n);
		if (cnt < k)
			left = mid + 1;
		else
			ans = mid, right = mid - 1;
	}
	cout << ans;
}