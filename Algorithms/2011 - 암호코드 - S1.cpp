/*
	1		=> A						=> 1��
	11		=> AA, K					=> 2��
	111		=> AAA, KA, AK				=> 3��
	1111	=> AAAA, KAA, AKA, KK, AAK	=> 5��
	11111	=> AAAAA, KAAA, AKAA, KKA, AAKA
			=> AAAK, KAK, AKK
	
	1		=> A						=> 1��
	10		=> J						=> 1��
	11		=> AA, K					=> 2��
	110		=> AJ
	1101	=> AJA
	11011	=> AJAA, AJK

	111		=> AAA, AK, KA
	1110	=> AAJ, KJ

	���� �þ ��
		���ĺ� �Ѱ�¥��.
						=> dp[i - 1] �߰�
		arr[i - 1]		1�̰� arr[i]�� 0 ~ 6
						2�̰� arr[i]�� 0 ~ 9 �� ��.
						=> dp[i - 2] �߰�
*/

#include <cstdio>
#define MOD 1000000
using namespace std;

int dp[5001] = { 1, 0 };

int main() {
	char prev = '\0', curr;
	int idx = 1;
	
	while ((curr = getchar()) != EOF && curr != '\n') {
		if (curr != '0') dp[idx] = dp[idx - 1];
		if ((prev == '1' && '0' <= curr && curr <= '9') ||
			prev == '2' && '0' <= curr && curr <= '6') {
			dp[idx] = (dp[idx] + dp[idx - 2]) % MOD;
		}
		prev = curr;
		idx++;
	}

	printf("%d", dp[idx - 1]);
}