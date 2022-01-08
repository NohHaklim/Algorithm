#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 16;

int N;
int Road[MAX][MAX];
// DP[방문한 도시의 비트][현재 도시] = 현재까지의 비용
int DP[1 << MAX][MAX];

int TSP(int cur, int visited)
{
	if (DP[visited][cur] != 0)
		return DP[visited][cur];

	if (visited == (1 << N) - 1)
	{
		if (Road[cur][0] != 0)
			return Road[cur][0];
		else
			return INF;
	}

	int res = INF;
	for (int i = 0; i < N; i++)
		if (!((1 << i) & visited) && (Road[cur][i] != 0))
			res = min(res, Road[cur][i] + TSP(i, visited + (1 << i)));
	DP[visited][cur] = res;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Road[i][j];

	cout << TSP(0, 1) << endl;
}