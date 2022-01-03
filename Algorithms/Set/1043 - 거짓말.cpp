#include <iostream>
#include <vector>
using namespace std;

int N, M, Cnt;
int Temp[2], Parent[51], Participant[51];
bool Know[51];

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
	cin >> Temp[0];
	
	for (int i = 1; i <= N; i++)
		Parent[i] = i;

	for (int i = 0; i < Temp[0]; i++)
	{
		cin >> Temp[1];
		Know[Temp[1]] = true;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> Temp[0] >> Participant[i];
		for (int j = 0; j < Temp[0] - 1; j++)
		{
			cin >> Temp[1];
			Union(Participant[i], Temp[1]);
		}
	}

	for (int i = 1; i <= N; i++)
		if (Know[i] == true)
			Know[Find(i)] = true;

	for (int i = 0; i < M; i++)
		if (Know[Find(Participant[i])] == false)
			Cnt++;

	cout << Cnt;
}