/*

* �ִܰ��
�׷������� �� ���� ������ ��ε� �߿��� ������ ����ġ�� ���� �ּ��� ���

* ���ͽ�Ʈ�� �˰���
�ϳ��� ���� �������� ��� �� �������� �ִ� ��θ� ���ϴ� �˰���
1) �ʱ�ȭ
	Graph[N][M] ���� i == j ��� 0, �׷��� �ʴٸ� INF ������ �ʱ�ȭ
2) ���⼺�� ���� ������ ��� �Է� �ޱ�
	�� ����� �ð��̳� �Ÿ��� �� �� �ִ�.
3) priority_queue�� �̿��� ���

*/

#include <iostream>
#include <queue>
using namespace std;

// ���� ���ǿ� ���� �޶����� ��
#define INF 987654321
#define MAX_N 10

typedef pair<int, int> pii;

int N, E;
int Graph[MAX_N][MAX_N], Dist[MAX_N];

void dijkstra(int src) {
	// {�� �������� ���� ���, ����}
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
		// �׷����� ���⼺�� ���� �޸� �ؾ���. ������ ������ �׷���
		Graph[u][v] = Graph[v][u] = cost;
	}

	// 0���� ����������.
	dijkstra(0);

	for (int i = 0; i < N; i++)
		cout << Dist[i] << ' ';
	cout << endl;
	return 0;
}