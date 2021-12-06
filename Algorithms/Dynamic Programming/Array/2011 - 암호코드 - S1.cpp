/*
	1		=> A						=> 1개
	11		=> AA, K					=> 2개
	111		=> AAA, KA, AK				=> 3개
	1111	=> AAAA, KAA, AKA, KK, AAK	=> 5개
	11111	=> AAAAA, KAAA, AKAA, KKA, AAKA
			=> AAAK, KAK, AKK
	
	1		=> A						=> 1개
	10		=> J						=> 1개
	11		=> AA, K					=> 2개
	110		=> AJ
	1101	=> AJA
	11011	=> AJAA, AJK

	111		=> AAA, AK, KA
	1110	=> AAJ, KJ

	한줄 늘어날 때
		알파벳 한개짜리.
						=> dp[i - 1] 추가
		arr[i - 1]		1이고 arr[i]가 0 ~ 6
						2이고 arr[i]가 0 ~ 9 일 때.
						=> dp[i - 2] 추가
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