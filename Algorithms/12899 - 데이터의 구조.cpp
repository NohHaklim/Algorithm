#include <iostream>
using namespace std;

class Tree
{
	int node[1 << 22];

public:
	int Insert(int cur, int left, int right, int value)
	{
		if (left == right)
			return ++node[cur];

		int mid = (left + right) / 2;
		if (value <= mid)
			Insert(cur * 2, left, mid, value);
		else
			Insert(cur * 2 + 1, mid + 1, right, value);
		return node[cur] = node[cur * 2] + node[cur * 2 + 1];
	}

	int Delete(int cur, int left, int right, int value)
	{
		if (left == right)
		{
			node[cur]--;
			return left;
		}

		int mid = (left + right) / 2, ret;
		if (value <= node[cur * 2])
			ret = Delete(cur * 2, left, mid, value);
		else
			ret = Delete(cur * 2 + 1, mid + 1, right, value - node[cur * 2]);
		node[cur] = node[cur * 2] + node[cur * 2 + 1];
		return ret;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, maxN = 2000000;
	cin >> N;

	Tree *t = new Tree();
	for (int i = 0; i < N; i++)
	{
		int T, X;
		cin >> T >> X;

		if (T == 1)
			t->Insert(1, 0, maxN - 1, X - 1);
		else
			cout << t->Delete(1, 0, maxN - 1, X) + 1 << "\n";
	}
}