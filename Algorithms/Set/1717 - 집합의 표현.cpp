#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000001;
int N, M;
int Parent[MAX];

int Find(int a)
{
	if (a == Parent[a])
		return a;
	return Parent[a] = Find(Parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	Parent[b] = a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		Parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int t, a, b;
		cin >> t >> a >> b;
		switch (t)
		{
		case 0:
			Union(a, b);
			break;
		case 1:
			int tempA = Find(a);
			int tempB = Find(b);
			if (tempA == tempB)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}