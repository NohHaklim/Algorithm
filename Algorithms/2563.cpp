/*
	ū ��ȭ���� �����̸� �� ���̰��� ���̸� ���ϴ� ���� �����ƺ���.
	100 * 100�� ĭ�� bool �������� ���� ����, �����̰� ���� �κ��� true�� �ٲٸ鼭
	����(s)�� 1�� �߰�.
	false �κ��� �׳� ����.
*/

#include <cstdio>

using namespace std;

bool space[101][101];

int main() {
	int n, cnt = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		for (int a = 0; a < 10; a++) {
			for (int b = 0; b < 10; b++) {
				if (space[x + a][y + b] == false) {
					cnt++;
					space[x + a][y + b] = true;
				}
			}
		}
	}

	printf("%d", cnt);
}