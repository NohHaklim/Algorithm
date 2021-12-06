/*
	1. 결과값을 이름으로 하는 배열 생성
	2. 점화식 찾기
	3. 초기값 설정
*/

#include <cstdio>
#define MIN2(a, b) (((a) < (b)) ? (a) : (b))
#define MIN3(a, b, c) ((MIN2(a, b)) < (c) ? (MIN2(a, b)) : (c))
#define MIN4(a, b, c, d) ((MIN3(a, b, c) < (d) ? ((MIN2(a, b)) < (c) ? (MIN2(a, b)) : (c)) : d))
using namespace std;

int BP[100001][3] = { 0 };
int DP[100001][3] = { 0 };

int main() {
	int k = 0;

	while (true) {
		int N;
		
		k++;
		scanf("%d", &N);
		if (N == 0) break;

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &BP[i][j]);
			}
		}
		
		DP[1][0] = BP[1][0];
		DP[1][1] = BP[1][1];
		DP[1][2] = BP[1][2];
		DP[2][0] = DP[1][1] + BP[2][0];
		DP[2][1] = MIN3(DP[2][0], DP[1][1], BP[1][1] + BP[1][2]) + BP[2][1];
		DP[2][2] = MIN3(DP[1][1], DP[2][1], BP[1][1] + BP[1][2]) + BP[2][2];
		for (int i = 3; i <= N; i++) {
			DP[i][0] = MIN2(DP[i - 1][0], DP[i - 1][1]) + BP[i][0];
			DP[i][1] = MIN4(DP[i][0], DP[i - 1][0], DP[i - 1][1], DP[i - 1][2]) + BP[i][1];
			DP[i][2] = MIN3(DP[i][1], DP[i - 1][1], DP[i - 1][2]) + BP[i][2];
		}
		printf("%d. %d\n", k, DP[N][1]);
	}
}