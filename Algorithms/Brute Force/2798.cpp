#include <cstdio>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int N, M;
int arr[101];
int max = 0;

void solve(int idx, bool choice, int sum, int cnt) {
	if (idx == N - 1 && cnt != 3) return;
	if (cnt == 3) {
		if (sum <= M) {
			max = MAX(max, sum);
		}
		return;
	}
	
	solve(idx + 1, true, sum + arr[idx + 1], cnt + 1);
	solve(idx + 1, false, sum, cnt);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	solve(0, true, arr[0], 1);
	solve(0, false, 0, 0);

	printf("%d", max);
}