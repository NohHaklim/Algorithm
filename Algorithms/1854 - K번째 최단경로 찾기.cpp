#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n, m, k;
vector<pii> graph[1001];
priority_queue<int> dist[1001];

void solve()
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, 1 });
	dist[1].push(0);

	while (!pq.empty())
	{
		int from = pq.top().second, cost = pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[from].size(); i++)
		{
			int to = graph[from][i].first, nCost = graph[from][i].second;
			if (dist[to].size() < k)
			{
				dist[to].push(cost + nCost);
				pq.push({ cost + nCost, to });
			}
			else if (dist[to].top() > nCost + cost)
			{
				dist[to].pop();
				dist[to].push(cost + nCost);
				pq.push({ cost + nCost, to });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	solve();

	for (int i = 1; i <= n; i++)
	{
		if (dist[i].size() != k)
			cout << "-1\n";
		else
			cout << dist[i].top() << endl;
	}
}