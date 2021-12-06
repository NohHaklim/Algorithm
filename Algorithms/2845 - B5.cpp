#include <cstdio>

using namespace std;

int main() {
	int L, P;
	scanf("%d %d", &L, &P);
	L *= P;

	for (int i = 0; i < 5; i++) {
		int B;
		scanf("%d", &B);
		printf("%d ", B - L);
	}
}