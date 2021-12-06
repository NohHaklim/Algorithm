#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int graph[101][101];
int visited[101];
bool searched;
queue <int> q;

void BFS(int from, int to) {
	q.push(from);
	visited[from] = 1;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0 && graph[v][i] == 1) {
				q.push(i);
				visited[i] = visited[v] + 1;

				if (i == to) {
					searched = true;
					return;
				}
			}
		}
	}
}

int main() {
	int from, to;
	scanf("%d", &N);
	scanf("%d %d", &from, &to);
	scanf("%d", &M);

	for (int i = 1; i <= M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u][v] = graph[v][u] = 1;
	}

	BFS(from, to);
	if (searched) printf("%d", visited[to] - 1);
	else printf("-1");
}