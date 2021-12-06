/*
	정수 x에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
	1. x가 3으로 나누어 떨어지면, 3으로 나눈다.
	2. x가 2로 나누어 떨어지면, 2로 나눈다.
	3. 1을 뺀다.
	연산 횟수를 최소화하여 x를 1로 만드시오.
	
	dp[x]는 x를 만드는 연산의 횟수
*/
#include <cstdio>
using namespace std;

int dp[1000001];

int solve(int x) {
	int tmp;
	if (x == 1) return 0;
	if (dp[x]) return dp[x];

	dp[x] = solve(x - 1) + 1;
	if (!(x % 2)) {
		tmp = solve(x / 2) + 1;
		if (dp[x] > tmp) dp[x] = tmp;
	}
	if (!(x % 3)) {
		tmp = solve(x / 3) + 1;
		if (dp[x] > tmp) dp[x] = tmp;
	}
	
	return dp[x];
}

int main() {
	int x, result;
	scanf("%d", &x);
	
	result = solve(x);
	printf("%d", result);
}