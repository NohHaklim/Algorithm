#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lld;

int n;
lld v[100001];

lld solve(int start, int end) {
	if (start == end)
		return 0;
	if (start + 1 == end)
		return v[start];

	int mid = (start + end) / 2;
	lld ret = max(solve(start, mid), solve(mid, end));

	int width = 1, left = mid, right = mid;
	lld height = v[mid];
	while (right - left + 1 < end - start) {
		lld p = left > start ? min(height, v[left - 1]) : -1;
		lld q = right < end - 1 ? min(height, v[right + 1]) : -1;
		if (p >= q) {
			height = p;
			left--;
		}
		else {
			height = q;
			right++;
		}
		ret = max(ret, (lld)++width * height);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (true) {
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		cout << solve(0, n) << "\n";
	}
}