#include <iostream>
using namespace std;

const int MAX = 201;
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

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int con;
			cin >> con;
			if (con == 1)
				Union(i, j);
		}
	}

	int route, tempA, tempB;
	cin >> route;
	tempA = Find(route);
	for (int i = 0; i < M - 1; i++)
	{
		cin >> route;
		tempB = Find(route);
		if (tempA != tempB)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}