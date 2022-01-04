#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100000];
using lld = long long;

lld solve(int s, int e)
{
	if (s == e)
		return 0;
	if (s + 1 == e)
		return A[s];

	int mid = (s + e) / 2;
	lld result = max(solve(s, mid), solve(mid, e));

	int w = 1, h = A[mid], l = mid, r = mid;
	while (r - l + 1 < e - s)
	{
		int p = s < l ? min(h, A[l - 1]) : -1;
		int q = r < e - 1 ? min(h, A[r + 1]) : -1;
		if (p >= q)
		{
			h = p;
			l--;
		}
		else
		{
			h = q;
			r++;
		}
		result = max(result, (lld)++w * h);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << solve(0, N);
}