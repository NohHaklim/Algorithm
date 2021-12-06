#include <cstdio>

using namespace std;

int main() {
	int cnt = 0, n;
	scanf("%d", &n);

	for (int i = 666; ; i++) {
		int temp = i;
		
		int cnt_6 = 0;
		while (temp) {
			if (temp % 10 == 6) {
				cnt_6++;
			}
			else cnt_6 = 0;

			if (cnt_6 == 3) {
				cnt++;
				break;
			}
			temp /= 10;
		}

		if (cnt == n) {
			printf("%d\n", i);
			break;
		}
	}
}