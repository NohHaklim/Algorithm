#include <iostream>
#include <algorithm>
using namespace std;

int N, M, MAX = 987654321;
int G[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a][b] = G[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
					continue;
				else if (G[i][k] && G[k][j])
				{
					if (G[i][j] == 0)
						G[i][j] = G[i][k] + G[k][j];
					else
						G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
				}
			}
		}
	}

	int ret = MAX, person = 1;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)
			sum += G[i][j];
		if (ret > sum)
		{
			ret = sum;
			person = i;
		}
	}

	cout << person << endl;
}