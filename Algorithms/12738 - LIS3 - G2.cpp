#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator iter;
vector<int> v;

int main() {
	int n;
	scanf("%d", &n);

	v.push_back(-1000000001);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);

		if (v.back() < temp) {
			v.push_back(temp);
		}
		else {
			int index = lower_bound(v.begin(), v.end(), temp) - v.begin();
			v[index] = temp;
		}
	}

	printf("%d", v.size() - 1);
}