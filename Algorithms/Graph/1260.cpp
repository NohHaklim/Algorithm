#include <cstdio>
#include <queue>
using namespace std;

int N;					// ������ ����
int M;					// ������ ����
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
		start�� ���������� �ϴ� DFS Ž��.
		start�� ������ ���� �̹湮 ������ ��� �� ������ DFS Ž��.
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