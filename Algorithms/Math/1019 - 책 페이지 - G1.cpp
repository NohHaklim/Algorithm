/*
		========= 내 생각 ==========
		1	:	9*0		0*0+1		1
		2	:	9*1		9*1+10		19
		3	:	90*2	90*2+100	280
		4	:	900*3	900*3+1000	3700

		N이 3665일 경우?
		1) N_len = 4, digit = 1000, first = 3
		2) N_len = 3일 때까지의 카운팅
		3) 1000 ~ 2999 까지의 수 카운팅
			0: 3 * (2 * 10 * 10)
			1: (10 * 10 * 10) + 3 * (2 * 10 * 10) => 3은 N_len - 1, 2는 first
		4) 3000 ~ 3665 까지의 카운팅
		
		========= 백준 풀이 ==========
		A = 10 / B = 39인 경우
		10, 11, 12, 13, 14, 15, 16, 17, 18, 19
		20, 21, 22, 23, 24, 25, 26, 27, 28, 29
		30, 31, 32, 33, 34, 35, 36, 37, 38, 39
		=> A ~ B 1의 자리 수는 0 ~ 9까지 각각 (3 - 1 + 1)개

		A = 1345 / B = 8742
		1. A를 1350으로 만들면서 각 자리수 계산 / B를 8739로 만들면서 각 자리수 계산
		2. 그리고 873 - 135 + 1 만큼 각 자리수 증가
		3. A = 135 / B = 873 으로 변경.
		4. A 값 135가 136로 바뀔 때, 1과 3과 5가 10씩 증가.
		   B 값 873가 872로 바뀔 때, 8과 7과 3이 10씩 증가
		5. A = 140 / B = 869 사이 각 숫자마다 (86 - 14 + 1) * 10만큼 증가.
***/
#include <cstdio>
using namespace std;

int flag[10];

int int_len(int N, int *digit, int *first) {
	int cnt = 0, prev;
	long long d = 1;
	while (N) {
		prev = N % 10;
		N /= 10;
		cnt++;
		d *= 10;
	}

	(*digit) = d / 10;
	(*first) = prev;
	return cnt;
}

int pow(int a, int b) {
	int temp = 1;
	while (b--) {
		temp *= a;
	}
	return temp;
}

void check(int i) {
	while (i) {
		flag[i % 10]++;
		i /= 10;
	}
}

void print() {
	for (int i = 0; i < 10; i++) {
		printf("%d ", flag[i]);
	}
	printf("\n");
}

int main() {
	int N, N_len, digit = 1, first;
	scanf("%d", &N);

	N_len = int_len(N, &digit, &first);

	if (N_len > 2) {
		int cnt_0 = 0, cnt_1 = 1;
		for (int i = 2; i < N_len; i++) {
			int temp = 9 * (i - 1) * pow(10, i - 2);
			cnt_0 = cnt_0 + temp;
			cnt_1 = cnt_1 + temp + pow(10, i - 1);
		}

		flag[0] += cnt_0;
		for (int i = 1; i < 10; i++) {
			flag[i] += cnt_1;
		}

		first--;
		flag[0] = flag[0] + ((N_len - 1) * (first * pow(10, N_len - 2)));
		for (int i = 1; i < 10; i++) {
			if (first >= i) flag[i] = flag[i] + pow(10, N_len - 1);
			flag[i] = flag[i] + ((N_len - 1) * (first * pow(10, N_len - 2)));
		}

		first++;
		for (int i = first * digit; i <= N; i++) {
			check(i);
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			check(i);
		}
	}

	print();
}