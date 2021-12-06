/*

* 최단경로
그래프에서 두 정점 사이의 경로들 중에서 간선의 가중치의 합이 최소인 경로

* 다익스트라 알고리즘
하나의 시작 정점에서 모든 끝 정점까지 최단 경로를 구하는 알고리즘
1) 초기화
	Graph[N][M] 에서 i == j 라면 0, 그렇지 않다면 INF 값으로 초기화
2) 방향성에 따른 간선의 비용 입력 받기
	그 비용은 시간이나 거리가 될 수 있다.
3) priority_queue를 이용한 계산

*/

#include <iostream>
#include <queue>
using namespace std;

// 문제 정의에 따라 달라지는 값
#define INF 987654321
#define MAX_N 10

typedef pair<int, int> pii;

int N, E;
int Graph[MAX_N][MAX_N], Dist[MAX_N];

void dijkstra(int src) {
	// {이 정점까지 오는 비용, 정점}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	bool visited[MAX_N] = { false };
	for (int i = 0; i < N; i++)
		Dist[i] = INF;
	Dist[src] = 0;
	pq.push({ 0, src });

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (visited[u])
			continue;

		visited[u] = true;
		for (int v = 0; v < N; v++) {
			if (Dist[v] > Dist[u] + Graph[u][v]) {
				Dist[v] = Dist[u] + Graph[u][v];
				pq.push({ Dist[v], v });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> E;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				Graph[i][j] = 0;
			else
				Graph[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		// 그래프의 방향성에 따라서 달리 해야함. 지금은 무방향 그래프
		Graph[u][v] = Graph[v][u] = cost;
	}

	// 0번을 시작점으로.
	dijkstra(0);

	for (int i = 0; i < N; i++)
		cout << Dist[i] << ' ';
	cout << endl;
	return 0;
}