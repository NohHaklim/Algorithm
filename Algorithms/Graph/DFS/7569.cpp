#include <cstdio>
#include <queue>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct tomato {
	int z, x, y;
};

int N, M, H;
int graph[100][100][100];
queue <tomato> q;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int dz[] = { 1, -1 };

bool isInside(int z, int x, int y) {
	if (0 <= z && z < H && 0 <= x && x < N && 0 <= y && y < M) {
		return true;
	}
	return false;
}

void BFS() {
	while (!q.empty()) {
		int z = q.front().z;
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(z, nx, ny) && graph[z][nx][ny] == 0) {
				graph[z][nx][ny] = graph[z][x][y] + 1;
				q.push({ z, nx, ny });
			}
		}

		for (int i = 0; i < 2; i++) {
			int nz = z + dz[i];

			if (isInside(nz, x, y) && graph[nz][x][y] == 0) {
				graph[nz][x][y] = graph[z][x][y] + 1;
				q.push({ nz, x, y });
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &M, &N, &H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &graph[i][j][k]);
				if (graph[i][j][k] == 1) {
					q.push({ i, j, k });
				}
			}
		}
	}

	BFS();

	int result = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (graph[i][j][k] == 0) {
					printf("-1");
					return 0;
				}
				result = MAX(result, graph[i][j][k]);
			}
		}
	}

	// 토마토가 하나도 없는 경우를 고려.
	if (result != 0) printf("%d", result - 1);
	else printf("0");
	return 0;
}