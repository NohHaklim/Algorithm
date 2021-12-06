#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Ret = -1;
int Table[500][500];
int D[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool Visited[500][500];

int dfs(int cnt, int x, int y) {
	if (cnt == 4) {
		return Table[x][y];
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + D[i][0], ny = y + D[i][1];
		
		if (0 <= nx && nx < N && 0 <= ny && ny < M && !Visited[nx][ny]) {
			Visited[nx][ny] = true;
			Ret = max(Ret, Table[x][y] + dfs(cnt + 1, nx, ny));
			Visited[nx][ny] = false;
		}
	}
	return Ret;
}

int 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Table[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Visited[i][j] = true;
			Ret = max(Ret, dfs(0, i, j));
			Visited[i][j] = false;
		}
	}
}