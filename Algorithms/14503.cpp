#include <cstdio>
using namespace std;

int N, M;
int r, c, dir;
int table[50][50];
int total;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void solve(int x, int y, int dir, int cnt) {
	if (table[x][y] == 0) {
		table[x][y] = 2;
		total++;
	}

	int nx = x + dx[(dir + 3) % 4];
	int ny = y + dy[(dir + 3) % 4];
	if (table[nx][ny] == 0) {
		solve(nx, ny, (dir + 3) % 4, 0);
	}
	else {
		if (cnt != 4) solve(x, y, (dir + 3) % 4, cnt + 1);
		else {
			nx = x + dx[(dir + 2) % 4];
			ny = y + dy[(dir + 2) % 4];
			if (table[nx][ny] != 1) {
				solve(nx, ny, dir, 0);
			}
			else {
				return;
			}
		}
	}
}

int main() {
	int cnt = 0;
	scanf("%d %d", &N, &M);
	// 0: ºÏ, 1: µ¿, 2: ³², 3: ¼­
	scanf("%d %d %d", &r, &c, &dir);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &table[i][j]);

	solve(r, c, dir, cnt);
	printf("%d", total);
}