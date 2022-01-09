#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using pii = pair<int, int>;

int dx[2][4] = { {-1, 0, 1, 0},
				{-1, -1, 1, 1} };
int dy[2][4] = { {0, 1, 0, -1},
				{-1, 1, 1, -1} };

string Triangle[10];
vector<pii> Ans;

bool is_valid(int x, int y)
{
	return ((0 <= x && x <= 9) && (0 <= y && y <= 9));
}

bool check(int i, int j, int type, int dir)
{
	int new_i1 = i + dx[type][dir], new_j1 = j + dy[type][dir];
	int new_i2 = i + dx[type][(dir + 1) % 4], new_j2 = j + dy[type][(dir + 1) % 4];

	if (is_valid(new_i1, new_j1) && is_valid(new_i2, new_j2))
		if (Triangle[new_i1][new_j1] == '1' && Triangle[new_i2][new_j2] == '1')
			return true;
	return false;
}

bool counting(int i, int j, int type, int dir)
{
	int cnt1 = 0, cnt2 = 0;
	int i1 = dx[type][dir], j1 = dy[type][dir];
	int i2 = dx[type][(dir + 1) % 4], j2 = dy[type][(dir + 1) % 4];
	int temp_i = i, temp_j = j;
	
	while (is_valid(temp_i + i1, temp_j + j1))
	{
		if (Triangle[temp_i + i1][temp_j + j1] == '1')
		{
			cnt1++;
			temp_i += i1, temp_j += j1;
		}
		else
			break;
	}
	Ans.push_back({ temp_i, temp_j });
	temp_i = i, temp_j = j;
	while (is_valid(temp_i + i2, temp_j + j2))
	{
		if (Triangle[temp_i + i2][temp_j + j2] == '1')
		{
			cnt2++;
			temp_i += i2, temp_j += j2;
		}
		else
			break;
	}
	if (cnt1 == cnt2)
	{
		Ans.push_back({ temp_i, temp_j });
		return true;
	}
	Ans.pop_back();
	return false;
}

bool cmp(pii a, pii b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < a.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for (int i = 0; i < 10; i++)
		cin >> Triangle[i];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Triangle[i][j] != '1')
				continue;
			for (int type = 0; type < 2; type++)
			{
				for (int dir = 0; dir < 4; dir++)
				{
					if (check(i, j, type, dir))
					{
						Ans.push_back({ i, j });
						if (counting(i, j, type, dir))
						{
							sort(Ans.begin(), Ans.end(), cmp);
							for (auto ans : Ans)
								cout << ans.first << " " << ans.second << endl;
							return 0;
						}
						Ans.pop_back();
					}
				}
			}
		}
	}
	cout << "0";
}