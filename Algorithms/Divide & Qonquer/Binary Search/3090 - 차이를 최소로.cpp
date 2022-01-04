#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5 + 1;

int n, t, min_idx;
int low, high;
long long cnt;
int a[MAX];
int copya[MAX];
int result[MAX];

bool isPossible(int limit)
{
	for (int i = 0; i < n; i++)
		copya[i] = a[i];
	cnt = 0;

	for (int i = 0; i < n - 1; i++)
	{
		while (copya[i + 1] - copya[i] > limit)
		{
			cnt += copya[i + 1] - (copya[i] + limit);
			copya[i + 1] = copya[i] + limit;
		}
	}

	for (int i = n - 1; i > 0; i--)
	{
		if (copya[i - 1] - copya[i] > limit)
		{
			cnt += copya[i - 1] - (copya[i] + limit);
			copya[i - 1] = copya[i] + limit;
		}
	}
	if (cnt > t)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	low = 0; high = 1e9 - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (isPossible(mid))
		{
			for (int i = 0; i < n; i++)
				result[i] = copya[i];
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
}