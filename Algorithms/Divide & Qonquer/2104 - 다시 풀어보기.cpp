#include <cstdio>
#include <algorithm>

using namespace std;
typedef unsigned long long llu;

int arr[100000];

llu solve(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return (llu)arr[s] * arr[s];

	int mid = (s + e) / 2;
	llu result = max(solve(s, mid), solve(mid + 1, e));

	llu sum = arr[mid];
	int l = mid, r = mid, m = arr[mid];
	while (r - l +1 < e - s) {
		int p = s < l ? min(arr[l - 1], m) : -1;
		int q = r < e - 1 ? min(m, arr[r + 1]) : -1;

		if (p >= q) {
			sum += arr[l - 1];
			m = p;
			l--;
		}
		else {
			sum += arr[r + 1];
			m = q;
			r++;
		}
		result = max(result, sum * m);
	}

	return result;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%llu", solve(0, N));
}
