/*
	배열을 돌면서 깊이 우선 탐색을 통해, 연결되는 모든 점을 찾는다.
*/

#include <cstdio>
using namespace std;

int N;
int cnt;
int node[101];
bool visited[101];
bool cycle[101];

bool DFS(int startNum, int nodeNum) {
	if (visited[nodeNum])
		return false;
	
	visited[nodeNum] = true;

	// 사이클 여부
	if (startNum == nodeNum || DFS(startNum, node[nodeNum])) {
		cnt++;
		cycle[nodeNum] = true;
		return true;
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &node[i]);

	for (int i = 1; i <= N; i++) {
		// cycle 정보와 visited 정보를 일치화 한다.
		for (int j = 1; j <= N; j++)
			visited[j] = cycle[j];
		DFS(i, node[i]);
	}

	printf("%d\n", cnt);
	for (int i = 1; i <= N; i++)
		if (cycle[i]) printf("%d\n", i);
}