#include <cstdio>
#include <vector>
#include <cmath>
#define MOD 1000000007
#define lld long long
using namespace std;

lld init(vector<lld> &a, vector<lld> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	return tree[node] = (init(a, tree, node * 2, start, (start + end) / 2) *
		init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
}

lld multiple(vector<lld> &tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 1;
	if (left <= start && end <= right) {
		return tree[node];
	}
	return (multiple(tree, node * 2, start, (start + end) / 2, left, right) *
		multiple(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;
}

void update(vector<lld> &tree, int node, int start, int end, int idx, int val) {
	if (idx < start || end < idx)
		return;
	if (start == end) {
		tree[node] = val;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, idx, val);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

void print_tree(vector<lld>& tree, int tree_size) {
	for (int i = 1; i < tree_size; i++)
		printf("%d ", tree[i]);
	printf("\n");
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<lld> a(n);
	int height = (int)ceil(log2(n));
	int tree_size = 1 << (height + 1);
	vector<lld> tree(tree_size);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	init(a, tree, 1, 0, n - 1);
	//print_tree(tree, tree_size);

	m += k;
	while (m--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		switch (t1) {
		case 1:
			a[--t2] = t3;
			update(tree, 1, 0, n - 1, t2, t3);
			break;
		case 2:
			t2--; t3--;
			printf("%lld\n", multiple(tree, 1, 0, n - 1, t2, t3));
			break;
		}
		//print_tree(tree, tree_size);
	}
}