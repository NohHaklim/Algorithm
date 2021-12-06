#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
}