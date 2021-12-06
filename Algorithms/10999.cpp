#include <cstdio>
#include <vector>
#include <cmath>
#define lld long long
using namespace std;

lld init(vector<lld> &a, vector<lld> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) +
			init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void update_lazy(vector<lld> &tree, vector<lld> &lazy, int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		// leaf가 아니라면
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(vector<lld> &tree, vector<lld> &lazy, int node, int start, int end, int left, int right, lld diff) {
	update_lazy(tree, lazy, node, start, end);
	if (right < start || end < left) 
		return;
	if (left <= start && end <= right) {
		tree[node] += (end - start + 1) * diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	update_range(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff);
	update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

lld sum(vector<lld> &tree, vector<lld> &lazy, int node, int start, int end, int left, int right) {
	update_lazy(tree, lazy, node, start, end);
	if (right < start || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right) +
		sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	M += K;

	vector<lld> a(N);
	int h = (int)ceil(log2(N));
	int tree_size = 1 << (h + 1);
	vector<lld> tree(tree_size);
	vector<lld> lazy(tree_size);
	for (int i = 0; i < N; i++)
		scanf("%lld", &a[i]);
	init(a, tree, 1, 0, N - 1);

	while (M--) {
		int t1;
		scanf("%d", &t1);
		switch (t1) {
		case 1:
			int start, end;
			lld diff;
			scanf("%d %d %lld", &start, &end, &diff);
			update_range(tree, lazy, 1, 0, N - 1, start - 1, end - 1, diff);
			break;
		case 2:
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%lld\n", sum(tree, lazy, 1, 0, N - 1, t2 - 1, t3 - 1));
			break;
		}
	}
}