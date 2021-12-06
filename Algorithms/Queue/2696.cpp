#include <cstdio>
#include <queue>
using namespace std;

int T, N;

void solve() {
	scanf("%d", &N);
	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int, vector<int>, less<int>> maxHeap;
	printf("%d\n", N / 2 + 1);
	for (int i = 1; i <= N; i++) {
		int n;
		scanf("%d", &n);

		// 1. maxHeap�� ũ�Ⱑ minHeap�� ũ��� ���ų� 1 �� ũ��.
		if (maxHeap.size() == minHeap.size()) maxHeap.push(n);
		else minHeap.push(n);
		// 2. maxHeap�� top�� minHeap�� top���� �۰ų� ����.
		if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int a = maxHeap.top(); maxHeap.pop();
			int b = minHeap.top(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}

		if (i & 1) {
			printf("%d", maxHeap.top());
			if (i < N) printf(" ");
		}
		if (i % 20 == 0) printf("\n");
		else if (i == N) printf("\n");
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}