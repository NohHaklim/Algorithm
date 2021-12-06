/*
	0/1 Knapsack problem�� ���� ��ȹ������ ���������ϴ�.
	DP[i ��° ���Ǳ��� ���� �� ���� ��][�ִ� ����] = �ִ� ����
	DP[0][~] = 0
	
	�߰��� i�� ���԰� j���� �۴ٸ�... => i�� �߰��� ���� ��ġ�� �ȵ� ���� ��ġ�� ��.
	if (w[i] <= j) DP[i][j] = MAX(DP[i - 1][j - w[i]] + v[i], DP[i - 1][j])
	�׷��� �ʴٸ�, �� �߰����� ���� ���� ��ġ�� �״�� ��.
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