#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int>;
const int MAX = 10000 + 1;

int N, M, Cnt;
vector<pii> V[MAX],Rv[MAX];
vector<int> D(MAX, 0);
vector<bool>Visit(MAX, false);

void dijkstra(int src, int dst)
{
	priority_queue<pii> pq;
	pq.push({ 0, src });

	while (!pq.empty())
	{
		int used_cost = pq.top().first, from = pq.top().second;
		pq.pop();

		if (D[from] != used_cost)
			continue;

		for (auto iter: V[from])
		{
			int to = iter.first, cost = iter.second;
			if (D[to] >= used_cost + cost)
				continue;
			D[to] = used_cost + cost;
			pq.push({ D[to], to });
		}
	}
}

void bfs(int src, int dst)
{
	queue<int> q;
	q.push(src);
	Visit[src] = true;
	
	while (!q.empty())
	{
		int from = q.front();
		q.pop();

		for (auto iter : Rv[from])
		{
			int to = iter.first, cost = iter.second;
			if (D[to] + cost != D[from])
				continue;
			Cnt++;
			if (!Visit[to])
			{
				q.push({ to });
				Visit[to] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		V[from].push_back({ to, cost });
		Rv[to].push_back({ from, cost });
	}

	int src, dst, ret;
	cin >> src >> dst;
	dijkstra(src, dst);
	bfs(dst, src);
	cout << D[dst] << endl << Cnt;
}