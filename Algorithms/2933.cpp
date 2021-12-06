#include <cstdio>
#include <queue>
#define MAX 100 + 1
#define MIN_FUNC(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int table[MAX][MAX];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int R, C;
int N;
queue<pair<int, int>> q;
queue<pair<int, int>> floating_q;

bool isInside(int y, int x) {
	if (0 < y && y <= R && 0 < x && x <= C)
		return true;
	return false;
}

void solve(int idx, int stick) {
	// 막대를 던져 맞춘 부분 제거.
	int height = R - stick + 1;
	if (idx & 1) {
		for (int i = 1; i <= C; i++) {
			if (table[height][i] == 'x') {
				table[height][i] = '.';
				break;
			}
		}
	}
	else {
		for (int i = C; i >= 1; i--) {
			if (table[height][i] == 'x') {
				table[height][i] = '.';
				break;
			}
		}
	}

	// 떠있는 부분 확인하기.
	bool is_not_floating[MAX][MAX] = { false, };
	bool is_bottom[MAX] = { false, };
	for (int i = 1; i <= C; i++) {
		if (is_not_floating[R][i] == false && table[R][i] == 'x') {
			q.push({ R, i });
			is_not_floating[R][i] = true;
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (isInside(ny, nx) && is_not_floating[ny][nx] == false
				&& table[ny][nx] == 'x') {
				q.push({ ny, nx });
				is_not_floating[ny][nx] = true;
			}
		}
	}

	// 떠있는 클러스터 자체와 그것의 바닥 부분 기록
	for (int i = R - 1; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			if (is_not_floating[i][j] == false && table[i][j] == 'x') {
				if (is_bottom[j] == false) {
					is_bottom[j] = true;
					q.push({ i, j });
				}
				floating_q.push({ i, j });
			}
		}
	}

	// 떠있는 클러스터와 가까운 바닥 사이의 거리 구하기.
	int min_differ = MAX;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		int cnt = 0;
		for (int i = y + 1; i <= R; i++) {
			if (table[i][x] == '.') cnt++;
			else {
				break;
			}
		}
		min_differ = MIN_FUNC(min_differ, cnt);
	}

	// 떠있는 클러스터 내려주기.
	while (!floating_q.empty()) {
		int y = floating_q.front().first;
		int x = floating_q.front().second;
		floating_q.pop();

		table[y][x] = '.';
		table[y + min_differ][x] = 'x';
	}

	/*
	printf("====================\n");
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%c", table[i][j]);
		}
		printf("\n");
	}
	printf("====================\n");
	*/
}

int main() {
	scanf("%d %d", &R, &C); getchar();
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			table[i][j] = getchar();
		}
		getchar();
	}

	/*
	printf("====================\n");
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%c", table[i][j]);
		}
		printf("\n");
	}
	printf("====================\n");
	*/

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int stick;
		scanf("%d", &stick);
		solve(i, stick);
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%c", table[i][j]);
		}
		printf("\n");
	}
}
