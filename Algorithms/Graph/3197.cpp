#include <cstdio>
#include <iostream>
#include <queue>
#define MAX 1500
using namespace std;

typedef struct {
	int i, j;
}pos;

int day;
int R, C;
char table[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
queue<pos> q;
queue<pos> next_q;
queue<pos> water;

bool isInside(int x, int y) {
	if (0 <= x && x < R && 0 <= y && y < C)
		return true;
	return false;
}

int main() {
	scanf("%d %d", &R, &C); getchar();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			table[i][j] = getchar();
			if (table[i][j] == 'L') {
				q.push({ i, j });
				water.push({ i, j });
			}
			if (table[i][j] == '.') water.push({ i, j });
		}
		getchar();
	}

	pos from = q.front(); q.pop();
	pos to = q.front(); q.pop();
	visited[from.i][from.j] = true;
	q.push(from);
	while (true) {
		while (!q.empty()) {
			int x = q.front().i;
			int y = q.front().j;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (isInside(nx, ny) && visited[nx][ny] == false) {
					visited[nx][ny] = true;
					if (table[nx][ny] == 'X') {
						next_q.push({ nx, ny });
					}
					else if (table[nx][ny] == 'L') {
						printf("%d", day);
						exit(0);
					}
					else if (table[nx][ny] == '.') {
						q.push({ nx, ny });
					}
				}
			}
		}

		q = next_q;
		while (!next_q.empty()) {
			int x = next_q.front().i;
			int y = next_q.front().j;
			next_q.pop();
			table[x][y] = '.';
		}

		int n = water.size();
		while (n--) {
			int x = water.front().i;
			int y = water.front().j;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isInside(nx, ny) && table[nx][ny] == 'X') {
					table[nx][ny] = '.';
					water.push({ nx, ny });
				}
			}
		}
		/*
		printf("======================\n");
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%c", table[i][j]);
			}
			printf("\n");
		}
		printf("======================\n");
		*/
		day++;
	}
}