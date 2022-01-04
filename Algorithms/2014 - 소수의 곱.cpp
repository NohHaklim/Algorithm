#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

using llu = unsigned long long;
int N, K;
llu A[101], Max = (llu)1 << 31;
priority_queue<llu, vector<llu>, greater<llu>> Q;
map<llu, bool> C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		llu value;
		cin >> value;
		A[i] = value;
		
	}

	Q.push(1);
	C[1] = true;
	llu max_value = 0;

	while (K--)
	{
		llu now = Q.top();
		Q.pop();

		for (int i = 0; i < N; i++)
		{
			llu next = now * A[i];
			
			if (C.count(next))
				continue;
			
			if (Q.size() > K)
				if (max_value <= next)
					continue;

			Q.push(next);
			max_value = max(max_value, next);
			C[next] = true;
		}
	}
	cout << Q.top();
}