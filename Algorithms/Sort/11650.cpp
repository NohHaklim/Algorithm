#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*
class coord {
public:
	int x, y;
};

vector<coord> v;

bool compare(coord a, coord b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		coord *xy = new coord();
		xy->x = x; xy->y = y;
		v.push_back(*xy);
	}

	sort(v.begin(), v.end(), compare);

	vector<coord>::iterator iter = v.begin();
	for (; iter != v.end(); iter++) {
		printf("%d %d\n", iter->x, iter->y);
	}
}
*/

int main() {
	int t;
	scanf("%d", &t);
	vector <pair<int, int> > v(t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < t; i++) {
		printf("%d %d \n", v[i].first, v[i].second);
	}
}