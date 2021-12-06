#include <cstdio>
#include <queue>
#define MAX_SIZE 1000 + 1
using namespace std;

typedef struct tomato {
	int x, y;
}tomato;

queue<tomato> q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int board[MAX_SIZE][MAX_SIZE];

bool isInside(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < M)
		return true;
	return false;
}
void BFS() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny) && board[nx][ny] == 0) {
				board[nx][ny] = board[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 1) q.push({ i, j });
		}
	}

	BFS();

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				printf("-1");
				return 0;
			}
			if (result < board[i][j]) {
				result = board[i][j];
			}
		}
	}
	printf("%d", result - 1);
	return 0;
}