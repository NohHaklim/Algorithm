#include <cstdio>
#include <queue>
using namespace std;

int N;					// 정점의 개수
int M;					// 간선의 개수
int graph[1001][1001];	// graph
bool visited[1001];
queue<int> q;

void printQ() {
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
	printf("\n");
}
void DFS(int start) {
	/*
		start를 시작점으로 하는 DFS 탐색.
		start와 인접한 점이 미방문 상태일 경우 그 점으로 DFS 탐색.
	*/
	q.push(start);
	visited[start] = true;
	for (int i = 1; i <= N; i++) {
		if (graph[start][i] == 1 && visited[i] == false) {
			DFS(i);
		}
	}
}

void BFS(int start) {
	queue<int> q_BFS;
	visited[start] = true;
	q.push(start);
	q_BFS.push(start);

	while (!q_BFS.empty()) {
		int v = q_BFS.front();
		q_BFS.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[v][i] == 1 && visited[i] == false) {
				visited[i] = true;
				q.push(i);
				q_BFS.push(i);
			}
		}
	}
}

int main() {
	int start;
	scanf("%d %d %d", &N, &M, &start);
	for (int i = 0; i < M; i++) {
		int v, u;
		scanf("%d %d", &v, &u);
		graph[v][u] = 1;
		graph[u][v] = 1;
	}
	
	DFS(start);
	printQ();
	for (int i = 1; i <= N; i++)
		visited[i] = false;

	BFS(start);
	printQ();
}