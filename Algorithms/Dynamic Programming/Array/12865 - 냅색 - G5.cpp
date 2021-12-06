/*
	0/1 Knapsack problem은 동적 계획법으로 구현가능하다.
	DP[i 번째 물건까지 넣을 수 있을 때][최대 무게] = 최대 이윤
	DP[0][~] = 0
	
	추가될 i의 무게가 j보다 작다면... => i가 추가될 때의 가치와 안될 때의 가치를 비교.
	if (w[i] <= j) DP[i][j] = MAX(DP[i - 1][j - w[i]] + v[i], DP[i - 1][j])
	그렇지 않다면, 그 추가되지 않을 때의 가치를 그대로 둠.
	else DP[i][j] = DP[i - 1][j]
*/
#include <cstdio>
#include <vector>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int N, K;
int w[101];
int v[101];
int DP[101][100001];

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (w[i] <= j) DP[i][j] = MAX(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
			else DP[i][j] = DP[i - 1][j];
		}	
	}
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1 ; i <= N; i++) {
		int weight, value;
		scanf("%d %d", &weight, &value);
		w[i] = weight;
		v[i] = value;
	}

	solve();

	printf("%d", DP[N][K]);
}