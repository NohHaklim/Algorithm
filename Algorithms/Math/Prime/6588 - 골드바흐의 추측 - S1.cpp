#include <cstdio>
#include <cmath>

using namespace std;

int N;
bool not_prime[10000001];

void eratosthenes() {
	for (int i = 2; i <= N; i++) {
		for (int j = i * i; j <= 1000000; j += i) {
			if (not_prime[j] == false)  not_prime[j] = true;
		}
	}
}

int main() {
	N = sqrt(1000000);

	eratosthenes();

	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;

		bool fail = true;
		for (int i = 2; i <= 1000000; i++) {
			if (not_prime[i] == false) {
				if (not_prime[n - i] == false) {
					printf("%d = %d + %d\n", n, i, n - i);
					fail = false;
					break;
				}
			}
		}
		if (fail) printf("Goldbach's conjecture is wrong.\n");
	}
}