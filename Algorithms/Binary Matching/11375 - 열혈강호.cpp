#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int N, M, A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int a)
{
	visited[a] = true;
	for (auto b : adj[a])
	{
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b]))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;
			adj[i].push_back(temp);
		}
	}

	int match = 0;
	fill(A + 1, A + MAX + 1, -1);
	fill(B + 1, B + MAX + 1, -1);
	for (int i = 1; i <= N; i++)
	{
		if (A[i] == -1)
		{
			fill(visited + 1, visited + MAX + 1, false);
			if (dfs(i))
				match++;
		}
	}

	cout << match;
}