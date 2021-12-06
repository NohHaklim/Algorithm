/*
		1 2 3 4 5 6 7 -6  => 22
		1 2 3 4 4 3 2 2 1
**/

#include <cstdio>
#include <cmath>

typedef long long lld;
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int x, y;
		scanf("%d %d", &x, &y);

		lld i;
		int range = y - x;
		for (i = 1; ; i++) {
			if (i * i > range) break;
		}
		i--;

		lld remained = range - (i * i);
		remained = (lld)ceil((double)remained / i);

		printf("%lld\n", 2 * i - 1 + remained);
	}
}