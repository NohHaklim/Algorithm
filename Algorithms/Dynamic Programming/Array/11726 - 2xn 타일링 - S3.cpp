/*
	2*N Ÿ�ϸ�
	=> DP[i��° ��] = �� Ÿ�ϸ� ������ ����� ��
	=> DP[i]	= Ÿ�� �ϳ��� �ϼ� + Ÿ�� �ΰ��� �ϼ�
				= DP[i - 1] + DP[i - 2]
*/
#include <cstdio>
using namespace std;

int main() {
	int N, DP[1001] = { 0 };
	scanf("%d", &N);

	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= N; i++)
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	printf("%d", DP[N]);
}