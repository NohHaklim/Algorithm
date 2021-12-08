#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, src, dst, max_weight;
vector<vector<pair<int, int>>> path;
bool visit[10001];

bool BFS(int weight)
{
	queue<int> q;
	q.push(src);
	visit[src] = true;

	while (!q.empty())
	{
		int from = q.front();
		q.pop();

		if (from == dst)
			return true;

		for (auto p : path[from])
		{
			int to = p.first, limit = p.second;
			
			if (visit[to])
				continue;
			if (weight > limit)
				continue;

			visit[to] = true;
			q.push(to);
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	path.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		path[from].push_back({ to, weight });
		path[to].push_back({ from, weight });
		if (max_weight < weight)
			max_weight = weight;
	}
	cin >> src >> dst;

	int low = 0, high = max_weight + 1;
	while (low <= high)
	{
		memset(visit, false, n + 1);
		int min = (low + high) / 2;
		if (BFS(min))
			low = min + 1;
		else
			high = min - 1;
	}
	cout << high;
}