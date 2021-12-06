#include <cstdio>
#define MAX 8 + 1
using namespace std;

int N, M;
int list[MAX];

void func(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (cnt > 0 && list[cnt - 1] > i) continue;
		list[cnt] = i;
		func(cnt + 1);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	func(0);
}