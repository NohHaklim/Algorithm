#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

#define MAX 100000 + 1

typedef pair<int, int> pii;

int N, K;
bool Visited[MAX];

int BFS() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, N });

	while (!pq.empty()) {
		int time = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (pos == K)
			return time;

		if (pos * 2 < MAX && !Visited[pos * 2]) {
			pq.push({ time, pos * 2 });
			Visited[pos * 2] = true;
		}

		if (pos + 1 < MAX && !Visited[pos + 1]) {
			pq.push({ time + 1, pos + 1 });
			Visited[pos + 1] = true;
		}
		if (pos - 1 >= 0 && !Visited[pos - 1]) {
			pq.push({ time + 1, pos - 1 });
			Visited[pos - 1] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	cout << BFS();
}