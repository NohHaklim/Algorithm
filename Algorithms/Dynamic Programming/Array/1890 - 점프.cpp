#include <iostream>
#include <vector>
using namespace std;

using ull = unsigned long long;

int n;
int table[100][100];
ull dp[100][100] = { 1, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> table[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] >= 1)
			{
				int move = table[i][j];
				if (!move)
					continue;
				if (i + move < n)
					dp[i + move][j] += dp[i][j];
				if (j + move < n)
					dp[i][j + move] += dp[i][j];
			}
		}
	}
	cout << dp[n - 1][n - 1];
}