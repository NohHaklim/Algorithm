#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000;

int t, N, M, A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int a)
{
	visited[a] = true;
	for (int b : adj[a])
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

	cin >> t;
	while (t--)
	{
		cin >> N >> M;

		for (int i = 0; i < MAX; i++)
			adj[i].clear();
		fill(visited, visited + MAX, false);
		fill(A, A + MAX, -1);
		fill(B, B + MAX, -1);

		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			for (int j = a - 1; j <= b - 1; j++)
				adj[i].push_back(j);
		}

		int match = 0;

		for (int i = 0; i < M; i++)
		{
			if (A[i] == -1)
			{
				fill(visited, visited + MAX, false);
				if (dfs(i))
					match++;
			}
		}
		cout << match << endl;
	}
}