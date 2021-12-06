/*
	카운팅 정렬
	수들의 갯수는 엄청 많은데, 그 수의 범위가 좁을 경우 쓸 수 있는 정렬법
*/

#include <cstdio>
using namespace std;

int arr[10001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (arr[i]) {
			printf("%d\n", i);
			arr[i]--;
		}
	}
}