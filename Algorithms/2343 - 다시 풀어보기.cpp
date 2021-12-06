#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> list;

int main() {
	int N, M, i; scanf("%d %d", &N, &M);
	int lo = 0, hi = 0;
	list = vector <int>(N + 1, 0);
	for (i = 0; i < N; i++) {
		scanf("%d", &list[i]);
		if (lo < list[i]) lo = list[i];
		hi += list[i];
	}
	list[i] = 1000000001;							// tmp + list[i + 1] 계산을 위해서;

	lo--;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int tmp = 0, cnt = 0;
		for (int i = 0; i < N; i++) {
			tmp += list[i];
			if (tmp + list[i + 1] > mid) {
				cnt++;
				tmp = 0;
			}
		}

		if (M < cnt) lo = mid;
		else hi = mid;
	}
	printf("%d", hi);
}