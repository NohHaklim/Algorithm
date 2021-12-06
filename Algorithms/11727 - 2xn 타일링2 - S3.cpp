/*
	2*N 타일링
	1*2 / 2*1 / 2*2 타일.
	=> DP[i번째 열] = 에 타일링 가능한 방법의 수
	=> DP[i]	= 타일 하나로 완성 + 타일 두개로 완성
				= DP[i - 1] + DP[i - 2]
*/
#include <cstdio>
using namespace std;

int main() {
	int N, DP[1001] = { 0 };
	scanf("%d", &N);

	DP[1] = 1;
	DP[2] = 3;
	for (int i = 3; i <= N; i++)
		DP[i] = (DP[i - 1] + (DP[i - 2] * 2)) % 10007;
	printf("%d", DP[N]);
}