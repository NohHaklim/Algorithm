#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
int N, L, R;
int Population[50][50];
int United[50][50];
int D[4][2] = { {1, 0}, {-1 ,0}, {0, 1}, {0, -1} };

bool canUnite(int cx, int cy, int nx, int ny)
{
	int a = Population[cx][cy], b = Population[nx][ny];
	if (b > a)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (L <= a - b && a - b <= R)
		return true;
	return false;
}

void bfs(int x, int y, int num)
{
	queue<pii> q;
	queue<pii> q2;
	int cnt = 0, sum = 0;

	q.push({ x, y });
	United[x][y] = num;
	q2.push({ x, y });

	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		cnt++;
		sum += Population[cx][cy];

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cx + D[dir][0], ny = cy + D[dir][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N
				|| United[nx][ny] != 0 || !canUnite(cx, cy, nx, ny))
				continue;
			United[nx][ny] = num;
			q.push({ nx, ny });
			q2.push({ nx, ny });
		}
	}

	int pop = sum / cnt;
	while (!q2.empty())
	{
		int cx = q2.front().first, cy = q2.front().second;
		q2.pop();
		Population[cx][cy] = pop;
	}
}

void move(int x, int y, int num)
{
	queue<pii> q;

	q.push({ x, y });
	United[x][y] = 0;

	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cx + D[dir][0], ny = cy + D[dir][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N
				|| United[nx][ny] != num)
				continue;
			United[nx][ny] = 0;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Population[i][j];
	
	int totalCnt = 0;
	while (true)
	{
		int num = 1;

		// bfs를 통해 연합을 구한 후, 그 연합원들의 인구를 조정한다.
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (United[i][j] == 0)
					bfs(i, j, num++);

		// 연합을 초기화 한다.
		if (United[N - 1][N - 1] == N * N)
			break;
		memset(United, 0, sizeof(United));

		// 연합이 안구해질 때까지 지속한다.
		totalCnt++;
	}
	cout << totalCnt;
}