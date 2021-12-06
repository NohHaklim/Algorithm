#include <iostream>
#include <queue>
#include <vector>
#define MAX_V 1000 + 1
#define INF 1000000000

using namespace std;

vector<pair<int, int>> graph[MAX_V];

void dijkstra(int N) {
	int S, E;
	cin >> S >> E;

	vector<int> dist(N + 1, INF);
	dist[S] = 0;
	priority_queue<pair<int, int>> pq;
	bool visited[MAX_V] = { false };
	pq.push(make_pair(0, S));

	while (!pq.empty()) {
		int from = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (visited[from])
			continue;
		if (dist[from] < cost)
			continue;
		visited[from] = true;

		for (int i = 0; i < graph[from].size(); i++) {
			int to = graph[from][i].first;
			int cost = graph[from][i].second;

			if (dist[from] + cost < dist[to]) {
				dist[to] = dist[from] + cost;
				pq.push(make_pair(-dist[to], to));
			}
		}
	}

	cout << dist[E];
}

int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
	}

	dijkstra(N);
}