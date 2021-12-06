/*
	재귀함수는 base 설정을 잘 해야함!
*/

#include <cstdio>
using namespace std;

void solve(int* arr, bool* flag, int N, int cur, bool check, int sum) {
	if (cur > N) return;
	
	flag[cur] = check;
	if (flag[cur]) {
		sum++;

		if (sum == 6) {
			for (int i = 1; i <= N; i++) {
				if (flag[i])
					printf("%d ", arr[i]);
			}
			printf("\n");
		}
	}
	
	solve(arr, flag, N, cur + 1, true, sum);
	solve(arr, flag, N, cur + 1, false, sum);
}

int main() {
	int n = 0;
	while (true) {
		int arr[50] = { 0 };
		bool flag[50] = { false };
		int N;

		scanf("%d", &N);
		if (N == 0) break;
		n++;
		if (n > 1) printf("\n");
		for (int i = 1; i <= N; i++)
			scanf("%d", &arr[i]);

		solve(arr, flag, N, 1, true, 0);
		solve(arr, flag, N, 1, false, 0);

	}
}