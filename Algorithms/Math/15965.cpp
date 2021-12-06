#include <cstdio>
#define MAX 8000000
using namespace std;

int K, cnt;
long long k_prime;
bool not_prime[MAX];

void eratosthenes() {
	for (long long i = 2; i < MAX; i++) {
		if (not_prime[i] == true) continue;
		else {
			cnt++;
			if (cnt == K) {
				k_prime = i;
				return;
			}
		}
		for (long long j = i * i; j <= MAX; j += i) {
			not_prime[j] = true;
		}
	}
}

int main() {
	scanf("%d", &K);

	eratosthenes();
	
	printf("%ld", k_prime);
}