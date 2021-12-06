#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct pos {
	int x, y;
};

int N, cnt;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int table[25][25];
int list[300];
queue <pos> q;

bool isInside(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < N) {
		return true;
	}
	return false;
}

int BFS(int i, int j) {
	int number = 1;
	table[i][j]++; // 방문 기록.
	q.push({ i, j });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny) && table[nx][ny] == 1) {
				q.push({ nx, ny });
				table[nx][ny]++;
				number++;
			}
		}
	}
	return number;
}

int main() {
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp = getchar();
			table[i][j] = temp - '0';
		}
		getchar();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] == 1) {
				list[cnt++] = BFS(i, j);
			}
		}
	}
	
	sort(list, list + cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", list[i]);
	}
}