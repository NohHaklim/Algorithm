#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, M, money[10000], maxBudget = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", money + i);
		maxBudget = max(maxBudget, money[i]);
	}
	scanf("%d", &M);

	int lo = 0, hi = maxBudget + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (money[i] > mid) sum += mid;
			else sum += money[i];
		}

		if (sum <= M) lo = mid;
		else hi = mid;
	}

	printf("%d", lo);
}