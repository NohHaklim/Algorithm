#include <cstdio>
#include <vector>

using namespace std;
typedef long long lld;

bool not_prime[2000001];
vector<int> prime;

void eratosthenes() {
	for (lld i = 2; i <= 2000000; i++) {
		if (not_prime[i] == false) prime.push_back(i);
		for (lld j = i * i; j <= 2000000; j += i) {
			if (not_prime[j] == false) not_prime[j] = true;
		}
	}
}

bool isPrime(lld A) {
	if (A <= 2000000) {
		return !not_prime[A];
	}
	else {
		for (int i = 0; i < prime.size(); i++) {
			if (A % prime[i] == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int T;
	scanf("%d", &T);

	eratosthenes();

	while (T--) {
		lld A, B;
		scanf("%lld %lld", &A, &B);

		A += B;
		
		if (A < 4) {
			printf("NO\n");
			continue;
		}
		if (A % 2 == 0) {
			printf("YES\n");
			continue;
			// °ñµå¹ÙÈåÀÇ ÃßÃø
		}

		A -= 2;
		if (isPrime(A)) printf("YES\n");
		else printf("NO\n");
	}
}