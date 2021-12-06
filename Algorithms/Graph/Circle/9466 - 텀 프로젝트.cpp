#include <iostream>
#include <stack>
#include <cstring>

using namespace std;


const int MAX = 100000 + 1;

int N, cnt;
int want[MAX];
bool visited[MAX];
bool done[MAX];

void dfs(int nodeNum)
{
	visited[nodeNum] = true;

	int next = want[nodeNum];
	if (!visited[next])
		dfs(next);
	else if (!done[next]) {
		for (int i = next; i != nodeNum; i = want[i]) {
			cnt++;
		}
		cnt++;
	}

	done[nodeNum] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));

		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> want[i];

		cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i])
				dfs(i);
		}

		cout << N - cnt << "\n";
	}
}