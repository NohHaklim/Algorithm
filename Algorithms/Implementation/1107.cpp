/*
	�ּ����� �������� ���ϴ� ��ȣ�� ���¹�.
	1. 100������ �����ϱ� ������, 100������ �ٷ� + or - �̿��ϴ� ���
	2. 100������ �ٸ� ��ȣ�� �̵� �� + or - �̿��ϴ� ���

	����)
	1. ���� ������ 0�� ��� ����! => length ���ϴ� ������ ������
	2. + ���� ���� ���� - ���� �� ������ ���� length�� �ٸ� �� ����.

	Ʋ�ȴ� �κ�)
	*. ���Ʈ ������ �ϱ� ���� ���� �� temp_a�� temp_b�� length�� ���ϸ鼭
	�� ���ڰ� ������ ������ üũ�ϵ��� �����ߴ��� �� �������ȴ�.
		=> ��� �۵����� ���� �Ẹ�� �غ��� �� �� ����.
	*. �ٸ� ������ ��� ���峭 ���, �˰����� �۵����� ������ �˾ƾ��ߴ�.
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