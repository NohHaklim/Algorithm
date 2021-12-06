#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int table[21][21];
int N, res = 200000, sum;
bool flag[21];

void solve(int n, int cnt) {
	if (cnt == N / 2) {
		int res1 = 0, res2 = 0;
		vector<int> v1, v2;
		for (int i = 1; i <= N; i++) {
			if (flag[i]) {
				v1.push_back(i);
			}
			else v2.push_back(i);
		}

		for (int i = 0; i < v1.size() - 1; i++) {
			for (int j = i + 1; j < v1.size(); j++) {
				res1 += table[v1[i]][v1[j]] + table[v1[j]][v1[i]];
				res2 += table[v2[i]][v2[j]] + table[v2[j]][v2[i]];
			}
		}
		res = min(res, abs(res1 - res2));
		return;
	}

	for (int i = n + 1; i <= N; i++) {
		flag[i] = true;
		solve(i, cnt + 1);
		flag[i] = false;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &table[i][j]);
		}
	}

	flag[1] = true;
	solve(1, 1);
	printf("%d", res);
}