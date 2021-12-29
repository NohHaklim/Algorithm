#include <iostream>
#include <vector>
using namespace std;

using ull = unsigned long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	ull max = 0;
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		max = max < v[i] ? v[i] : max;
	}

	ull lo = 1, hi = max * m;
	while (lo <= hi)
	{
		ull mid = (lo + hi) / 2;
		ull cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += (mid / v[i]);
		if (cnt >= m)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	cout << lo;
}