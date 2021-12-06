/*
	1. 문제 이해
		B는 치킨을 먹을 때, 쿠폰으로 먹는 치킨임에도 쿠폰을 받을 수 있다.
		따라서 5장의 쿠폰으로 치킨을 먹어서 3장의 쿠폰을 받는다면, 결국 2장의 쿠폰으로
		치킨을 먹을 수 있는 것이다.
	2. 시뮬레이션
		15장 => 13장(1마리) => 11장(2마리) => 9장(3마리) => 7장(4마리)
		=> 5장(5마리) => 3장(6마리)
	3. 코딩
		마지막에 먹는 닭은 따로 빼두고, 계산하자!
		if (남은 쿠폰 수 - F > 0) (남은 쿠폰 수 - F) / (F - C) + 1
*/

#include <cstdio>
using namespace std;

int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int P, M, F, C;
		scanf("%d %d %d %d", &P, &M, &F, &C);
		
		int a, b, a_N, b_N;
		a = b = M / P;			// 돈으로 먹은 치킨 수
		a_N = b_N = a * C;		// 남은 쿠폰 수

		a += a_N / F;
		if ((b_N - F) >= 0) b += (b_N - F) / (F - C) + 1;

		printf("%d\n", b - a);
	}
}