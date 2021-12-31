#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string board, ans = "";
	cin >> board;
	for (int i = 0; i < board.length(); i++)
	{
		if (board[i] == 'X')
		{
			int cnt = 0;
			for (int j = i; board[j] == 'X' && j < board.length(); j++)
				cnt++;
			if (cnt % 2 == 0)
			{
				for (int j = 0; j < cnt / 4; j++)
					ans += "AAAA";
				if (cnt % 4)
					ans += "BB";
			}
			else
			{
				cout << -1;
				return 0;
			}
			i += (cnt - 1);
		}
		else
			ans += '.';
	}
	cout << ans;
}