#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long lld;
vector<pii> v;
lld tree[1 << 20];

bool cmp(pii a, pii b)
{
	return a.second < b.second;
}

lld sum_query(int cur, int start, int end, int qs, int qe)
{
	if (qe < start || end < qs)
		return 0;
	if (qs <= start && end <= qe)
		return tree[cur];

	int mid = (start + end) >> 1;
	return sum_query(cur * 2, start, mid, qs, qe)
		+ sum_query(cur * 2 + 1, mid + 1, end, qs, qe);
}

void update(int cur, int start, int end, int idx)
{
	if (start == end)
	{
		tree[cur] = 1;
		return;
	}

	int mid = (start + end) >> 1;
	if (idx <= mid)
		update(cur * 2, start, mid, idx);
	else
		update(cur * 2 + 1, mid + 1, end, idx);
	tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;  cin >> n;

	for (int i = 0; i < n; i++)
	{
		int value; cin >> value;
		v.push_back({ i, value });
	}
	stable_sort(v.begin(), v.end(), cmp);

	lld cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int idx = v[i].first;
		cnt += sum_query(1, 0, n - 1, idx + 1, n - 1);
		update(1, 0, n - 1, idx);
	}
	cout << cnt;
}