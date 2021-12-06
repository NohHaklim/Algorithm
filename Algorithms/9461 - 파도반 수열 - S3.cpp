#include <cstdio>>

typedef unsigned long long llu;
using namespace std;

llu P[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);

		for (int i = 11; i <= N; i++) {
			P[i] = P[i - 1] + P[i - 5];
		}
		
		printf("%llu\n", P[N]);
	}
}