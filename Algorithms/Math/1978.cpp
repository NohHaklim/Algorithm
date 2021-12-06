#include <cstdio>

int main() {
	int number, n, i, j, loop = 0;
	// 1은 소수가 아님.
	int arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
	scanf("%d", &number);
	for (i = 0; i < number; i++) {
		scanf("%d", &n);
		for (j = 0; j < 11; j++) {
			if (n == 1)			break;
			if (n == arr[j]) {
				j++;
				break;
			}
			if (!(n % arr[j])) {
				j = 0;
				break;
			}
		}
		if (j)
			loop++;
	}
	printf("%d", loop);
}