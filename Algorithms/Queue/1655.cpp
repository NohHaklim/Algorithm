/*
	근데 대단하다. 사람이 어떻게 이런 생각을 하지...?
	들어온 배열을 반띵해서, 왼쪽 제일 위의 값을 출력해야해.
	그러니 왼쪽 배열은 MaxHeap에, 오른쪽 배열은 MinHeap에 넣는거지.
*/
#include <cstdio>
#include <queue>
using namespace std;

int N;

void solve() {
	priority_queue<int, vector <int>, greater <int>> MinHeap;
	priority_queue<int, vector <int>, less <int>> MaxHeap;
	while (N--) {
		int n;
		scanf("%d", &n);
		// 1. MaxHeap의 size는 MinHeap의 size보다 1 크거나 같다.
		if (MaxHeap.size() == MinHeap.size()) MaxHeap.push(n);
		else MinHeap.push(n);
		// 2. MaxHeap의 top은 MinHeap의 top보다 작거나 같아야 한다.
		if (!MinHeap.empty() && MaxHeap.top() > MinHeap.top()) {
			int a = MaxHeap.top(); MaxHeap.pop();
			int b = MinHeap.top(); MinHeap.pop();
			MaxHeap.push(b); MinHeap.push(a);
		}

		printf("%d\n", MaxHeap.top());
	}
}

int main() {
	scanf("%d", &N);
	solve();
}