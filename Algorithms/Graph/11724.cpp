#include <cstdio>
#include <queue>
using namespace std;

int N, M, cnt;
int table[1001][1001];
bool visited[1001];
queue <int> q;

void BFS(int start) {
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visited[i] == false && table[v][i] == 1) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		table[u][v] = 1;
		table[v][u] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			BFS(i);
			cnt++;
		}
	}
	printf("%d", cnt);
}