#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {	
	scanf("%d", &N);
	vector <int> v(N);

	for (int i = 0; i < N; i++) {
		v[i] = i + 1;
	}

	do {
		for (int i = 0; i < N; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
	} while (next_permutation(v.begin(), v.end()));
}