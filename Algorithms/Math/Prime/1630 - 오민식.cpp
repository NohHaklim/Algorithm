#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

int N;
int mod = 987654321;
bool prime[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<int> primes;

	for (int i = 2; i <= N; i++)
		for (int j = i * 2; j <= N; j += i)
			prime[j] = true;
	for (int i = 2; i <= N; i++)
		if (!prime[i])
			primes.push_back(i);
	ull ret = 1;
	for (auto p : primes) {
		if (p > N) break;
		ull k = p;
		while (k * p <= N) k *= p;
		ret = (ret * k) % mod;
	}
	cout << ret;
}