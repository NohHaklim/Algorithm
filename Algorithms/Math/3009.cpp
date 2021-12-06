#include <cstdio>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, int>> v(3);

	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	int x = v[0].first == v[1].first ? v[2].first : (v[0].first == v[2].first ? v[1].first : v[0].first);
	int y = v[0].second == v[1].second ? v[2].second : (v[0].second == v[2].second ? v[1].second : v[0].second);

	printf("%d %d", x, y);
}