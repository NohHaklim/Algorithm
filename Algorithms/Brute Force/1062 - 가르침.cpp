#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K, Result;
bool Visited[26];
string Words[50];

void solve(int alpha, int cnt)
{
	if (cnt == K)
	{
		int temp = 0;
		for (int i = 0; i < N; i++)
		{
			bool flag = true;
			for (int j = 0; j < Words[i].length(); j++)
			{
				if (!Visited[Words[i][j] - 'a'])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				temp++;
		}
		Result = max(Result, temp);
	}

	for (int i = alpha; i < 26; i++)
	{
		if (!Visited[i])
		{
			Visited[i] = true;
			solve(i, cnt + 1);
			Visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	
	if (K == 26)
	{
		cout << N << endl;
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> Words[i];
		Words[i] = Words[i].substr(4);
		for (int j = 0; j < 4; j++)
			Words[i].pop_back();
	}

	Visited['a' - 'a'] = true;
	Visited['c' - 'a'] = true;
	Visited['i' - 'a'] = true;
	Visited['n' - 'a'] = true;
	Visited['t' - 'a'] = true;
	K -= 5;

	solve(0, 0);
	cout << Result;
}