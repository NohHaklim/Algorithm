#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

/*
	a:		�Է¹��� �迭
	tree:	���׸�Ʈ Ʈ��
	node:	���׸�Ʈ Ʈ�� ��� ��ȣ
	�� node�� ����ϴ� ���� ���� start ~ end
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
	node[start, end] �������� [left, right]�� ���� ���Ϸ��� �Ѵ�.
	1. [left, right] �� [start, end] �� ��ġ�� �ʴ� ���
	2. [left, right] �� [start, end] �� ������ �����ϴ� ���
	3. [start, end]  �� [left, right]�� ������ �����ϴ� ���
	4. [left, right] �� [start, end] �� ������ �ִ� ��� (������ ���)
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
	index�� ���� ������ ���.
	1. [start, end]�� index�� ���ԵǴ� ���
	2. [start ,end]�� index�� ���Ե��� �ʴ� ���
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
	int tree_size = 1 << (h + 1);	// root�� 1���� �����ϹǷ�. ���� ������ 2^h - 1�̴�.
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