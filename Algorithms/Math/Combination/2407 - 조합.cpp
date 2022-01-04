#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string T[101][101];

string Add(string a, string b)
{
	int sum = 0;
	string res;

	while (!a.empty() || !b.empty() || sum)
	{
		if (!a.empty())
		{
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty())
		{
			sum += b.back() - '0';
			b.pop_back();
		}
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

string solve(int n, int m)
{
	if (n == m || m == 0)
		return T[n][m] = "1";
	if (T[n][m] == "")
		T[n][m] = Add(solve(n - 1, m - 1), solve(n - 1, m));
	return T[n][m];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	cout << solve(n, m);
}