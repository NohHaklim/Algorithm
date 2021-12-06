#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int table[1001][1001];
int cache[1001][1001][2];
int N, M;
int res = 987654321;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

bool isInside(int nx, int ny) {
	if (1 <= nx && nx <= N && 1 <= ny && ny <= M)
		return true;
	return false;
}

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 1));
	cache[1][1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int break_cnt = q.front().second;
		q.pop();

		if (x == N && y == M) {
			return cache[x][y][break_cnt];
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (isInside(nx, ny)) {
				if (table[nx][ny] == 1 && break_cnt == 1) {
					cache[nx][ny][break_cnt - 1] = cache[x][y][break_cnt] + 1;
					q.push(make_pair(make_pair(nx, ny), break_cnt - 1));
				}
				else if (table[nx][ny] == 0 && cache[nx][ny][break_cnt] == 0) {
					cache[nx][ny][break_cnt] = cache[x][y][break_cnt] + 1;
					q.push(make_pair(make_pair(nx, ny), break_cnt));
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &N, &M);
	
	getchar();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c = getchar();
			table[i][j] = c - '0';
		}
		getchar();
	}

	printf("%d", bfs());
}

/***

6 7
0111111
0111111
0111110
0110000
0110111
0000000

***/