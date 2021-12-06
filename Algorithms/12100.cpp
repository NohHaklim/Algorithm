#include <cstdio>
#include <queue>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int N;
int board[20][20];
int maxScore;

void shift(int dir) {
	queue<int> q;

	switch (dir) {
	case 0:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[i][idx] == 0)
					board[i][idx] = data;
				else if (board[i][idx] == data)
					board[i][idx++] *= 2;
				else
					board[i][++idx] = data;
			}
		}
		break;
	case 1:
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}

			int idx = N - 1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[i][idx] == 0)
					board[i][idx] = data;
				else if (board[i][idx] == data)
					board[i][idx--] *= 2;
				else
					board[i][--idx] = data;
			}
		}
		break;
	case 2:
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[idx][j] == 0)
					board[idx][j] = data;
				else if (board[idx][j] == data)
					board[idx++][j] *= 2;
				else
					board[++idx][j] = data;
			}
		}
		break;
	case 3:
		for (int j = 0; j < N; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}

			int idx = N - 1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[idx][j] == 0)
					board[idx][j] = data;
				else if (board[idx][j] == data)
					board[idx--][j] *= 2;
				else
					board[--idx][j] = data;
			}
		}
		break;
	}
}

void DFS(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				maxScore = MAX(maxScore, board[i][j]);
		return;
	}

	int copyBoard[20][20];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			copyBoard[i][j] = board[i][j];

	for (int i = 0; i < 4; i++) {
		shift(i);
		DFS(cnt + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = copyBoard[i][j];
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	DFS(0);
	printf("%d", maxScore);
	return 0;
}