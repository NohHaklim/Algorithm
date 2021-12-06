#include <cstdio>
#include <vector>
#include <queue>
#define MAX 32000 + 1
using namespace std;

int N, M;
int inDegree[MAX];
vector <int> graph[MAX];

void topologicalSort() {
	// 1. ���� ������ 0�� �������� queue�� �ִ´�.
	// 2. queue�� �ִ� ����� ������ ������ ������ �� �����ϰ�, queue���� ���� ���� topology�� �ִ´�.
	// �̸� �ݺ��Ѵ�.

	queue <int> q;
	int idx = 1;
	
	for (int i = 1; i <= N; i++)
		if (inDegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		printf("%d ", cur);
		for (int i = 0; i < graph[cur].size(); i++) {
			inDegree[graph[cur][i]]--;
			if (inDegree[graph[cur][i]] == 0)
				q.push(graph[cur][i]);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		inDegree[v2]++;
	}

	topologicalSort();
}