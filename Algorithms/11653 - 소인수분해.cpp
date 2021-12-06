#include <cstdio>

using namespace std;

int n;
bool not_prime[10000001];

void eratosthenes() {
	for (int i = 2; ; i++) {
		int j = i * i;
		if (j > n) break;
		for (; j <= n; j += i) {
			if (not_prime[j] == false) not_prime[j] = true;
		}
	}
}

int main() {
	scanf("%d", &n);

	eratosthenes();
	
	for (int i = 2; i <= n; i++) {
		if (not_prime[i] == false) {
			while (n % i == 0) {
				n /= i;
				printf("%d\n", i);
			}
		}	
	}
}