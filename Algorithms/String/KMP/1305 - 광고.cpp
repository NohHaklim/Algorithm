#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string p)
{
	int m = (int)p.length(), j = 0;
	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	string s;

	cin >> n >> s;
	auto pi = getPi(s);
	cout << n - pi[n - 1];
}