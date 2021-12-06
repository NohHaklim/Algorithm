#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, S, arr[100000];
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	long long sum = 0;
	int j = 0, len = 100001;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
		while (sum >= S && j <= i) {
			len = min(len, i - j + 1);
			sum -= arr[j++];
		}
	}

	if (len == 100001) printf("0");
	else printf("%d", len);
}