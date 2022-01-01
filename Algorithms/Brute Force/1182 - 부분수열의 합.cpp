#include <iostream>
using namespace std;

int N, S, Cnt, Arr[40];

void solve(int idx, int sum)
{
	if (N <= idx)
		return;
	sum += Arr[idx];
	if (sum == S)
		Cnt++;
	solve(idx + 1, sum - Arr[idx]);
	solve(idx + 1, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	solve(0, 0);
	cout << Cnt;
}