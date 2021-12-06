#include <cstdio>
#include <queue>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct pos {
	int x, y;
};

int N, M;
int table[8][8];
queue <pos> q;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int maxSpace;

bool isInside(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < M)
		return true;
	return false;
}

void virusSpread() {
	int copyTable[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copyTable[i][j] = table[i][j];
			if (table[i][j] == 2) q.push({ i, j });
		}
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny) && table[nx][ny] == 0) {
				table[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int space = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (table[i][j] == 0) space++;
	maxSpace = MAX(maxSpace, space);	

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			table[i][j] = copyTable[i][j];
}

void DFS(int cnt) {
	if (cnt == 3) {
		virusSpread();
		return;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (table[i][j] == 0) {
				table[i][j] = 1;
				DFS(cnt + 1);
				table[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &table[i][j]);

	DFS(0);
	printf("%d", maxSpace);
}