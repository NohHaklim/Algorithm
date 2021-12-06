#include <cstdio>

using namespace std;
typedef long long lld;

bool flag[1000001];
lld MIN, MAX, F, cnt;

int main() {
	scanf("%lld %lld", &MIN, &MAX);

	cnt = MAX - MIN + 1;

	for (lld i = 2; i * i <= MAX; i++) {
		lld start = MIN / (i * i);
		if (start * i * i != MIN) start++;

		for (lld j = start; j * i * i <= MAX; j++) {
			if (flag[(i * i * j) - MIN] == false) {
				flag[(i * i * j) - MIN] = true;
				cnt--;
			}
		}
	}

	printf("%lld\n", cnt);
}

/*
	1000000000000 1000001000000	-> 6
	10000 1000000	-> 601843
	500000 1234567	-> 446564
	1 500			-> 306
*/