/**
			��� �� - ġŲ�� �� ���� ����� �Ÿ��� dfs�� ã�Ƽ� ���Ѵ�.
			���� ���� ���� ���� ����� ���� ġŲ �Ÿ��� ���Ѵ�.
			
**/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, ret = 987654321;
bool flag[50];
vector<pair<int, int>> chicken_v;
vector<pair<int, int>> house_v;

int cal_dist(int i, int j) {
	return abs(house_v[i].first - chicken_v[j].first) + 
		abs(house_v[i].second - chicken_v[j].second);
}

void solve(int n, int cnt) {
	if (cnt == M) {
		int sum = 0;
		for (int i = 0; i < house_v.size(); i++) {
			int res = 987654321;
			for (int j = 0; j < chicken_v.size(); j++) {
				if (flag[j] == true) {
					int dist = cal_dist(i, j);
					res = min(res, dist);
				}
			}
			sum += res;
		}

		ret = min(ret, sum);
		return;
	}

	for (int i = n + 1; i < chicken_v.size(); i++) {
		flag[i] = true;
		solve(i, cnt + 1);
		flag[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int value;
			cin >> value;
			if (value == 2) {
				chicken_v.push_back(make_pair(i, j));
			}
			if (value == 1) {
				house_v.push_back(make_pair(i, j));
			}
		}
	}

	solve(-1, 0);
	printf("%d", ret);
}