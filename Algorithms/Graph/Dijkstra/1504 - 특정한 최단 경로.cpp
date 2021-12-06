#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 800 + 1
#define INF 987654321

/*
	다익스트라 => O(n^2) = 640,000
	플로이드-워셜 => O(n^3) = 512,000,000 => 5초...
*/

typedef pair<int, int> pii;

int N, E;
int V1, V2;
vector<pii> Graph[MAX];

int dijkstra(int src, int dst) {
	vector<int> dist(N + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dist[src] = 0;
	pq.push({ 0, src });

	while (!pq.empty()) {
		int from = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[from] < cost)
			continue;

		for (int i = 0; i < Graph[from].size(); i++) {
			int to = Graph[from][i].first;
			int cost = Graph[from][i].second;

			if (dist[from] + cost < dist[to]) {
				dist[to] = dist[from] + cost;
				pq.push({ dist[to], to });
			}
		}
	}

	return dist[dst];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		Graph[u].push_back({ v, cost });
		Graph[v].push_back({ u, cost });
	}

	cin >> V1 >> V2;

	int ret = min(dijkstra(1, V1) + dijkstra(V1, V2) + dijkstra(V2, N)
		, dijkstra(1, V2) + dijkstra(V2, V1) + dijkstra(V1, N));
	if (ret >= INF || ret < 0)
		cout << "-1";
	else
		cout << ret;
}