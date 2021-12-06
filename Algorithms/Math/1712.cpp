/*
	A + Bx < Cx 인 구간 x를 구하라?
*/

#include <cstdio>
using namespace std;

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	C -= B;

	if (C <= 0) {
		printf("-1");
	}
	else {
		int K = A / C;
		K++;
		printf("%d", K);
	}
}