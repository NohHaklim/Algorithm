/*
	큰 도화지에 색종이를 다 붙이고나서 넓이를 구하는 것은 귀찮아보임.
	100 * 100의 칸을 bool 형식으로 만든 다음, 색종이가 붙은 부분을 true로 바꾸면서
	넓이(s)를 1씩 추가.
	false 부분은 그냥 냅둠.
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