#include <cstdio>

using namespace std;

bool not_prime[4000001];

void eratosthenes(int n) {
	for (int i = 2; ; i++) {
		int j = i * i;
		if (j > n) break;
		for (; j <= n; j += i) {
			not_prime[j] = true;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	eratosthenes(n);

	long long sum = 0;
	int prev = 2, cnt = 0;
	
	for (int i = 2; i <= n; i++) {
		if (not_prime[i] == false) {
			sum += i;
			while (sum > n) {
				sum -= prev;
				for (int j = prev + 1; ; j++) {
					if (not_prime[j] == false) {
						prev = j;
						break;
					}
				}
			}
			if (sum == n) {
				cnt++;
			}
				
		}
	}

	printf("%d", cnt);
}