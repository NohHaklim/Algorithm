#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int n, k;
typedef pair<int, int> pii;
vector<pii> v;
bool visited[1001];

int need(pii from, pii to)
{
	int dist;
	
	dist = ceil(sqrt(pow(from.first - to.first, 2) + pow(from.second - to.second, 2)));
	if (dist % 10 != 0)
		dist += 10;
	return (int)(dist / 10);
}

bool bfs(int limit)
{
	queue<pair<pii, int>> q;
	q.push({ {0, 0}, 0} );

	while (!q.empty())
	{
		pii from = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt > k)
			continue;
		for (int i = 0; i < v.size(); i++)
		{
			if (visited[i])
				continue;
			int oil = need(from, v[i]);
			if (limit < oil)
				continue;

			if (v[i].first == 10000 && v[i].second == 10000)
				return true;
			visited[i] = true;
			q.push({ v[i], cnt + 1 });
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int row, col;
		cin >> row >> col;
		v.push_back({row, col});
	}
	v.push_back({ 10000, 10000 });

	int low = -1;
	int high = 2001;
	while (low <= high)
	{
		memset(visited, false, 1001);
		int mid = (low + high) / 2;
		if (bfs(mid))
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << low;
}