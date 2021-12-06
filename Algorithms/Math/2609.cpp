#include <cstdio>
using namespace std;

int main() {
	int num1, num2, i, max;
	scanf("%d %d", &num1, &num2);
	max = 1;
	for (i = 1; i <= num1; i++) {
		if (!(num1 % i) && !(num2 % i)) max = i;
	}
	printf("%d\n%d", max, num1 * num2 / max);
}