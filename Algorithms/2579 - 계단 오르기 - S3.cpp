/*
	DP[몇 번째 계단?][연속 수] = 총 점수.
	DP[N][1 ~ 2] 중 최댓값.
*/
#include <cstdio>
#define MAX2(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int BP[301];
int DP[301][3];
int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &BP[i]);
	}

	DP[1][1] = BP[1];
	DP[1][2] = 0;
	DP[2][1] = BP[2];
	DP[2][2] = DP[1][1] + BP[2];
	for (int i = 1; i <= N; i++) {
		DP[i][1] = MAX2(DP[i - 2][1], DP[i - 2][2]) + BP[i];
		DP[i][2] = DP[i - 1][1] + BP[i];
	}
	printf("%d", MAX2(DP[N][1], DP[N][2]));
}