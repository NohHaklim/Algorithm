#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100 + 1

int N, M;
string Maze[MAX];
bool Visited[MAX][MAX];

struct Pos {
	int x, y;
	int cnt;
};

struct comp {
	bool operator()(const Pos &p1, const Pos &p2) {
		return p1.cnt > p2.cnt;
	}
};

int D[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isValid(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > M)
		return false;
	return true;
}

int BFS() {
	priority_queue<Pos, vector<Pos>, comp> pq;

	Pos src;
	src.x = 1, src.y = 1, src.cnt = 0;
	Visited[1][1] = true;
	pq.push(src);

	while (!pq.empty()) {
		int x = pq.top().x, y = pq.top().y, cnt = pq.top().cnt;
		pq.pop();

		if (x == N && y == M)
			return cnt;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + D[dir][0];
			int ny = y + D[dir][1];

			if (!isValid(nx, ny))
				continue;

			if (Visited[nx][ny])
				continue;
			Visited[nx][ny] = true;

			Pos temp;
			temp.x = nx;
			temp.y = ny;
			temp.cnt = ((Maze[nx][ny] == '1') ? cnt + 1 : cnt);
			pq.push(temp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Maze[i];
		Maze[i] = '0' + Maze[i];
	}

	cout << BFS();
}