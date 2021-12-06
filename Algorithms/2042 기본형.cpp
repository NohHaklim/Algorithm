#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

/*
	a:		입력받은 배열
	tree:	세그먼트 트리
	node:	세그먼트 트리 노드 번호
	이 node가 담당하는 합의 범위 start ~ end
*/
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	// leaf node
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2)
			+ init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

/*
	node[start, end] 구간에서 [left, right]의 합을 구하려고 한다.
	1. [left, right] 와 [start, end] 가 겹치지 않는 경우
	2. [left, right] 가 [start, end] 를 완전히 포함하는 경우
	3. [start, end]  가 [left, right]를 완전히 포함하는 경우
	4. [left, right] 와 [start, end] 가 겹쳐져 있는 경우 (나머지 경우)
*/
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, node * 2, start, (start + end) / 2, left, right) +
		sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

/*
	index의 수를 변경할 경우.
	1. [start, end]에 index가 포함되는 경우
	2. [start ,end]에 index가 포함되지 않는 경우
*/
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (index < start || end < index) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	vector<long long> a(N);
	int h = (int)ceil(log2(N));
	int tree_size = 1 << (h + 1);	// root가 1부터 시작하므로. 원래 개수는 2^h - 1이다.
	vector<long long> tree(tree_size);

	M += K;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	init(a, tree, 1, 0, N - 1);

	while (M--) {
		int t1;
		scanf("%d", &t1);
		if (t1 == 1) {
			int t2;
			long long t3;
			scanf("%d %lld", &t2, &t3);
			t2 -= 1;
			long long diff = t3 - a[t2];
			a[t2] = t3;
			update(tree, 1, 0, N - 1, t2, diff);
		}
		else if (t1 == 2) {
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%lld\n", sum(tree, 1, 0, N - 1, t2 - 1, t3 - 1));
		}
	}
}