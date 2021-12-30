#include <iostream>
using namespace std;

int arr[100000];
class Tree {
	int node[1 << 18];

public:
	int init(int cur, int left, int right) {
		if (left == right) {
			return node[cur] = arr[left];
		}
		int mid = (left + right) / 2;
		return node[cur] = init(cur * 2, left, mid)
				+ init(cur * 2 + 1, mid + 1, right);
	}

	int del(int cur, int left, int right, int rank) {
		if (left == right) {
			node[cur] -= 1;
			return left;
		}
		int mid = (left + right) / 2;
		int ret = 0;
		if (rank <= node[cur * 2])
			ret = del(cur * 2, left, mid, rank);
		else
			ret = del(cur * 2 + 1, mid + 1, right, rank - node[cur * 2]);
		node[cur] = node[cur * 2] + node[cur * 2 + 1];
		return ret;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		arr[i] = 1;
	}
	Tree *t = new Tree();
	t->init(1, 0, N - 1);

	int rank = K;

	cout << "<";
	for (int i = 0; i < N; i++) {
		cout << t->del(1, 0, N - 1, rank) + 1;

		if (i < N - 1) {
			rank = (rank + K - 2) % (N - i - 1) + 1;
			cout << ", ";
		}
	}
	cout << ">";
}