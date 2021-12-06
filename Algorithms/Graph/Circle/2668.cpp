/*
	�迭�� ���鼭 ���� �켱 Ž���� ����, ����Ǵ� ��� ���� ã�´�.
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

	// ����Ŭ ����
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
		// cycle ������ visited ������ ��ġȭ �Ѵ�.
		for (int j = 1; j <= N; j++)
			visited[j] = cycle[j];
		DFS(i, node[i]);
	}

	printf("%d\n", cnt);
	for (int i = 1; i <= N; i++)
		if (cycle[i]) printf("%d\n", i);
}