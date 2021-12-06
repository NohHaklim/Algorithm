#include <cstdio>
#include <queue>
#define MAX 1000000 + 1
using namespace std;

int F;	// Floor
int S;	// Start
int G;	// Goal
int U;	// Up
int D;	// Down
int visited[MAX];
queue <int> q;

bool isInside(int N) {
	if (1 <= N && N <= F)
		return true;
	return false;
}

void BFS() {
	while (!q.empty()) {
		int N = q.front();
		q.pop();

		if (isInside(N + U) && visited[N + U] == 0) {
			visited[N + U] = visited[N] + 1;
			q.push(N + U);
		}
		if (isInside(N - D) && visited[N - D] == 0) {
			visited[N - D] = visited[N] + 1;
			q.push(N - D);
		}

		if (visited[G] != 0) {
			return;
		}
		
	}
}

int main() {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	visited[S] = 1;
	q.push(S);

	BFS();

	if (visited[G] != 0) printf("%d", visited[G] - 1);
	else printf("use the stairs");
}