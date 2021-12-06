#include <cstdio>

typedef unsigned long long llu;
using namespace std;

int main() {
	llu A, B, C, res = 1;
	scanf("%llu %llu %llu", &A, &B, &C);

	A %= C;
	while (B) {
		if (B & 1) {
			res *= A;
			res %= C;
		}
		A *= A;
		A %= C;
		B >>= 1;
	}

	printf("%llu", res);
}