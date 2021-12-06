#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	if (N != 1) {
		for (int i = 1; i < N; i++) {
			printf(" ");
		}
		printf("*\n");
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - i; j++) {
			printf(" ");
		}
		printf("*");
		for (int j = 1; j <= 2 * i - 1; j++) {
			printf(" ");
		}
		printf("*\n");
	}

	for (int i = 1; i < 2 * N; i++) {
		printf("*");
	}
}