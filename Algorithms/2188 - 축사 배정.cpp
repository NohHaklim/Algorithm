#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 200;
int N, M, A[MAX], B[MAX];
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

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int k;
			cin >> k;
			adj[i].push_back(k - 1);
		}
	}

	int match = 0;
	// �ʱⰪ: -1
	fill(A, A + N, -1);
	fill(B, B + M, -1);
	for (int i = 0; i < N; i++)
	{
		if (A[i] == -1)
		{
			fill(visited, visited + MAX, false);
			if (dfs(i))
				match++;
		}
	}
	cout << match;
}