/*
	lower_bound(n)	=> n 이상의 값이 처음으로 나오는 위치를 리턴.
	upper_bound(n)	=> n 초과의 값이 처음으로 나오는 위치를 리턴.
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	
	sort(v.begin(), v.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int value;
		scanf("%d", &value);
		//value가 vector에 있는지 체크.
		int idx = lower_bound(v.begin(), v.end(), value) - v.begin();
		
		if (idx != N && v[idx] == value) printf("1\n");
		else printf("0\n");
	}
}