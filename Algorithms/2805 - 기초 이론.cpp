/*
	[lo, hi)	=> while (lo + 1 < hi)
				=> lo = mid + 1 / hi = mid - 1
				=> result = lo or hi;

	[lo, hi]	=> while (lo <= hi)
				=> lo = mid / hi = mid
				=> result = mid;

/*
2512)
hi를 100001로 뒀을 경우의 반례.
4
10 11 12 13
46
100000의 결과가 뜬다... 왜? 100000으로 끊어도 4개의 예산 다 품을 수 있거든.
가능한 값 중 최댓값 + 1로 잡아야 할 거 같아.

나무 자르기에서는 왜 100000001으로 잡아도 됐을까?
자른 나무 길이들의 최댓값이므로, lo쪽으로 작아지기 때문이야.
*/
*/

#include <cstdio>
#include <vector>

using namespace std;
typedef long long lld;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	int lo = 0, hi = 1000000000;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		lld sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid < v[i]) sum += v[i] - mid;
		}

		if (sum >= M) lo = mid;
		else hi = mid;
	}

	printf("%d", lo);
}