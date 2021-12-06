/*
	최소한의 선택으로 원하는 번호로 가는법.
	1. 100번에서 시작하기 때문에, 100번에서 바로 + or - 이용하는 경우
	2. 100번에서 다른 번호로 이동 후 + or - 이용하는 경우

	주의)
	1. 도착 지점이 0일 경우 주의! => length 구하는 로직의 주의점
	2. + 했을 때의 값과 - 했을 때 나오는 값의 length가 다를 수 있음.

	틀렸던 부분)
	*. 브루트 포스를 하기 위해 만든 수 temp_a와 temp_b의 length를 구하면서
	그 숫자가 가능한 수인지 체크하도록 구성했더니 좀 꼬여버렸다.
		=> 어떻게 작동할지 말로 써보고 해봐야 할 것 같다.
	*. 다른 수들이 모두 고장난 경우, 알고리즘이 작동하지 않음을 알아야했다.
*/

#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

bool impossible[10];

int main() {
	int number, n;
	
	scanf("%d", &number);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		impossible[temp] = true;
	}

	int a = number;
	int b = a;
	int cnt = 0;
	int K = abs(100 - a);

	if (n == 10) {
		printf("%d", K);
		return 0;
	}

	while (true) {
		int temp_a = a;
		int temp_b = b;
		int len_a = 0;
		int len_b = 0;
		bool flag1 = true, flag2 = true;

		while (true) {
			len_a++;
			if (impossible[temp_a % 10] == true) {
				flag1 = false;
				break;
			}
			temp_a /= 10;
			if (temp_a == 0) break;
		}
		while (true) {
			len_b++;
			if (impossible[temp_b % 10] == true) {
				flag2 = false;
				break;
			}
			temp_b /= 10;
			if (temp_b == 0) break;
		}
		if (flag1 == true || flag2 == true) {
			int len = 100;
			if (flag1 == true) len = len_a;
			if (flag2 == true) len = len < len_b ? len : len_b;
			cnt = cnt + len;
			printf("%d", cnt < K ? cnt : K);
			break;
		}
		
		cnt++;
		if (a > 0) a--;
		b++;
	}
}