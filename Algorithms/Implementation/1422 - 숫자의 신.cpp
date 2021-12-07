#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k, max_num;
vector<string> v;

bool cmp(string a, string b)
{
	return a + b > b + a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> k >> n;
	v.resize(k);
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
		if (max_num < stoi(v[i]))
			max_num = stoi(v[i]);
	}
	sort(v.begin(), v.end(), cmp);

	if (n == k)
		for (int i = 0; i < k; i++)
			cout << v[i];
	else
	{
		bool flag = false;
		for (int i = 0; i < k; i++)
		{
			cout << v[i];
			if (!flag && max_num == stoi(v[i]))
			{
				flag = true;
				for (int j = 0; j < n - k; j++)
					cout << v[i];
			}
		}
	}
}