#include <cstdio>
#include <queue>
using namespace std;

int M, N;
int Board[100][100];
int Leftover;
int Melted;
int Day;

int D[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool isValid(int x, int y) {
	if (x < 0 || M <= x || y < 0 || N <= y)
		return false;
	return true;
}

void melt(bool visited[][100], int x, int y) {
	queue<pair<int, int>> q;

	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + D[dir][0], ny = cy + D[dir][1];

			if (!isValid(nx, ny) || visited[nx][ny] || Board[nx][ny] != 0)
				continue;

			for (int i = 0; i < 4; i++) {
				int nnx = nx + D[i][0], nny = ny + D[i][1];

				if (!isValid(nnx, nny) || Board[nnx][nny] != 1)
					continue;

				Board[nnx][nny] = 2;
			}

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

void exec_melt() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (Board[i][j] == 2) {
				Board[i][j] = 0;
				Melted++;
			}
		}
	}
}

void solution() {
	if (Leftover == 0)
		return;

	while (Leftover - Melted != 0) {
		Leftover -= Melted;
		bool visited[100][100] = { false };
		Melted = 0;
		Day++;

		for (int row = 0; row < M; row++) {
			if (!visited[row][0] && Board[row][0] == 0)
				melt(visited, row, 0);
			if (!visited[row][N - 1] && Board[row][N - 1] == 0)
				melt(visited, row, 0);
		}

		for (int col = 0; col < N; col++) {
			if (!visited[0][col] && Board[0][col] == 0)
				melt(visited, 0, col);
			if (!visited[M - 1][col] && Board[M - 1][col] == 0)
				melt(visited, 0, col);
		}

		exec_melt();
	}
}

int main() {
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Board[i][j]);
			if (Board[i][j] == 1)
				Leftover++;
		}
	}

	solution();

	printf("%d\n%d", Day, Leftover);
}