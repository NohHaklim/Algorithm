/*
	�ٵ� ����ϴ�. ����� ��� �̷� ������ ����...?
	���� �迭�� �ݶ��ؼ�, ���� ���� ���� ���� ����ؾ���.
	�׷��� ���� �迭�� MaxHeap��, ������ �迭�� MinHeap�� �ִ°���.
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
		// 1. MaxHeap�� size�� MinHeap�� size���� 1 ũ�ų� ����.
		if (MaxHeap.size() == MinHeap.size()) MaxHeap.push(n);
		else MinHeap.push(n);
		// 2. MaxHeap�� top�� MinHeap�� top���� �۰ų� ���ƾ� �Ѵ�.
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