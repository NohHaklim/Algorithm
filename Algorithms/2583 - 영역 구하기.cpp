#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int Board[100][100];
bool Visited[100][100];
vector<int> answer;

int D[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isValid(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N)
		return false;
	return true;
}

void bfs(int x, int y) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	
	while (!q.empty()) {
		int cx = q.front().first, cy = q.front().second;
		
		Visited[cx][cy] = true;
		q.pop();
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + D[dir][0], ny = cy + D[dir][1];

			if (!isValid(nx, ny) || Visited[nx][ny] || Board[nx][ny] == 1)
				continue;
			Visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	
	answer.push_back(cnt);
}

int main() {
	scanf("%d %d %d", &M, &N, &K);

	for (int n = 0; n < K; n++) {
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				Board[j][i] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!Visited[i][j] && Board[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	sort(answer.begin(), answer.end());

	printf("%d\n", cnt);
	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer[i]);
	}
}