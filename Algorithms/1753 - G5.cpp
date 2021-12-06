#include <iostream>
#include <vector>
#include <queue>
#define MAX 20000 + 1
#define INF 300000

using namespace std;

vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int S, int V) {
	vector<int> dist(V + 1, INF);
	dist[S] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, S));
	
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		
		if (dist[here] < cost) continue;

		vector<pair<int, int>>::iterator iter = graph[here].begin();
		for (; iter != graph[here].end(); iter++) {
			int there = iter->first;
			int cost = iter->second;

			if (dist[here] + cost < dist[there]) {
				dist[there] = dist[here] + cost;
				pq.push(make_pair(-dist[there], there));
			}
		}
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int V, E, S;
	cin >> V >> E >> S;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	vector<int> dist = dijkstra(S, V);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}