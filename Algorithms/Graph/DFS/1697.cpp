#include <cstdio>
#include <queue>
#define MAX 100000 + 1
using namespace std;

int N, K;
int load[MAX];
queue <int> q;

bool isInside(int n) {
	if (0 <= n && n <= 100000) {
		return true;
	}
	return false;
}

void BFS() {
	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (isInside(n + 1) && load[n + 1] == 0) {
			q.push(n + 1);
			load[n + 1] = load[n] + 1;
		}
		if (isInside(n - 1) && load[n - 1] == 0) {
			q.push(n - 1);
			load[n - 1] = load[n] + 1;
		}
		if (isInside(2 * n) && load[2 * n] == 0) {
			q.push(2 * n);
			load[2 * n] = load[n] + 1;
		}

		if (load[K] != 0) {
			return;
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	q.push(N);
	load[N] = 1;

	BFS();
	printf("%d", load[K] - 1);
}