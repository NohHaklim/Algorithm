#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, cnt1 = 0, cnt2 = 0;
	string board[100];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != '.')
				continue;
			j++;
			bool flag = false;
			while (j < n && board[i][j] == '.' && (flag = true))
				j++;
			if (flag)
				cnt1++;
			j--;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] != '.')
				continue;
			j++;
			bool flag = false;
			while (j < n && board[j][i] == '.' && (flag = true))
				j++;
			if (flag)
				cnt2++;
			j--;
		}
	}
	cout << cnt1 << " " << cnt2;
}