#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
string Table[100];
int D[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool visited[100][100];

bool isValid(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;
	return true;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + D[i][0], ny = cy + D[i][1];

			if (!isValid(nx, ny) || Table[nx][ny] != Table[x][y])
				continue;

			if (visited[nx][ny] == true)
				continue;
			visited[nx][ny] = true;

			q.push({ nx, ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cnt1 = 0, cnt2 = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Table[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				bfs(i, j);
				cnt1++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			if (Table[i][j] == 'G')
				Table[i][j] = 'R';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				bfs(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt1 << " " << cnt2;
}