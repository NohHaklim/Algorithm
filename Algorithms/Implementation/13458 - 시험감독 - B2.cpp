#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int T, B, C;
	long long sum = 0;

	scanf("%d", &T);
	vector<int> A(T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d %d", &B, &C);

	for (int i = 0; i < T; i++) {
		if (A[i] > 0) {
			sum++;
			A[i] -= B;
			
			if (A[i] > 0) sum = sum + (int)ceil((double)A[i] / C);
		}
	}

	printf("%lld", sum);
}