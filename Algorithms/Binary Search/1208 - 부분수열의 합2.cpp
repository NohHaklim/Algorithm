#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, Arr[40];
long long Cnt;
vector<int> A, B;

void makeA(int idx, int sum)
{
	if (N / 2 <= idx)
		return;
	sum += Arr[idx];
	if (sum == S)
		Cnt++;
	A.push_back(sum);
	makeA(idx + 1, sum - Arr[idx]);
	makeA(idx + 1, sum);
}

void makeB(int idx, int sum)
{
	if (N <= idx)
		return;
	sum += Arr[idx];
	if (sum == S)
		Cnt++;
	B.push_back(sum);
	makeB(idx + 1, sum - Arr[idx]);
	makeB(idx + 1, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	makeA(0, 0);
	makeB(N / 2, 0);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < A.size(); i++)
	{
		int temp = S - A[i];
		int lower = lower_bound(B.begin(), B.end(), temp) - B.begin();
		int upper = upper_bound(B.begin(), B.end(), temp) - B.begin();
		Cnt += upper - lower;
	}
	cout << Cnt;
}