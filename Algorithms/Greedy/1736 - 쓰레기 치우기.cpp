#include <iostream>
using namespace std;

int N, M;
int Trash = 0, Ret = 0;
int Board[100][100];

void clean(int x, int y)
{
	if (x == N - 1 && y == M - 1)
		return;

	for (int i = x; i < N; i++)
	{
		for (int j = y; j < M; j++)
		{
			if (Board[i][j] == 1)
			{
				Board[i][j] = 0;
				Trash--;
				clean(i, j);
				return;
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Board[i][j];
			if (Board[i][j] == 1)
				Trash++;
		}
	}

	while (Trash)
	{
		Ret++;
		clean(0, 0);
	}
	cout << Ret;
}