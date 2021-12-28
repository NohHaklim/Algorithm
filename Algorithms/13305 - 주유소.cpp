#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, prev_city = 0, curr_city = 0, sum_dist = 0;
	ull cost = 0;
	int road[100001];

	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> road[i];

	cin >> prev_city;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> curr_city;
		if (prev_city < curr_city)
			sum_dist += road[i];
		else
		{
			sum_dist += road[i];
			cost += ((ull)sum_dist * prev_city);
			sum_dist = 0;
			prev_city = curr_city;
		}
	}
	if (sum_dist)
		cost += ((ull)sum_dist * prev_city);
	cout << cost;
}