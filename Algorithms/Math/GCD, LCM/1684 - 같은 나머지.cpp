#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1000];

int gcd(int a, int b)
{
	while (b)
	{
		int mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	sort(A, A + N);
	for (int i = 1; i < N; i++)
		A[i - 1] = A[i] - A[i - 1];
	int r = A[0];
	for (int i = 1; i < N - 1; i++)
		r = gcd(r, A[i]);
	cout << r;
}