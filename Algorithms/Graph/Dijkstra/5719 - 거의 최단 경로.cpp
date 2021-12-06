#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define MAX 500
#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int N, M, S, D;
vector<pii> graph[MAX];
vector<pii> trace[MAX];
bool visited[MAX][MAX];

int dijkstra(int S, int D)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(MAX, INF);
	dist[S] = 0;
	pq.push({ 0, S });

	while (!pq.empty())
	{
		int from = pq.top().second, cost = pq.top().first;
		pq.pop();

		if (dist[from] < cost)
			continue;

		for (int i = 0; i < graph[from].size(); i++)
		{
			int to = graph[from][i].first, nCost = graph[from][i].second;

			if (nCost == -1)
				continue;

			if (dist[to] > cost + nCost)
			{
				dist[to] = cost + nCost;
				pq.push({ dist[to], to });

				trace[to].clear();
				trace[to].push_back({ from, dist[to] });
			}
			else if (dist[to] == cost + nCost)
			{
				trace[to].push_back({ from, dist[to] });
			}
		}
	}
	return dist[D];
}

void bfs(int D)
{
	queue<int> q;
	q.push(D);

	while (!q.empty())
	{
		int from = q.front();
		q.pop();

		for (int i = 0; i < trace[from].size(); i++)
		{
			int to = trace[from][i].first;
			if (visited[from][to])
				continue;
			visited[from][to] = true;
			
			for (int j = 0; j < graph[to].size(); j++)
			{
				if (graph[to][j].first == from)
				{
					graph[to][j].second = -1;
				}
			}
			q.push(to);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (true)
	{
		memset(visited, false, sizeof(visited));
		memset(trace, 0, sizeof(trace));
		for (int i = 0; i < MAX; i++)
			graph[i].clear();

		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		
		cin >> S >> D;

		for (int i = 0; i < M; i++)
		{
			int u, v, p;
			cin >> u >> v >> p;
			graph[u].push_back({ v, p });
		}

		dijkstra(S, D);
		bfs(D);
		int ret = dijkstra(S, D);
		if (ret < 0 || ret >= INF)
			cout << "-1\n";
		else
			cout << ret << endl;
	}
}