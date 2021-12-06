#include <cstdio>
#include <algorithm>
#define MAX 8 + 1
using namespace std;

int N, M;
int arr[MAX];
int list[MAX];
bool visited[MAX];

void func(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			if (cnt > 0 && list[cnt - 1] > arr[i]) continue;
			visited[i] = true;
			list[cnt] = arr[i];
			func(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + N + 1);

	func(0);
}