/*
	lower_bound(n)	=> n �̻��� ���� ó������ ������ ��ġ�� ����.
	upper_bound(n)	=> n �ʰ��� ���� ó������ ������ ��ġ�� ����.
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
		//value�� vector�� �ִ��� üũ.
		int idx = lower_bound(v.begin(), v.end(), value) - v.begin();
		
		if (idx != N && v[idx] == value) printf("1\n");
		else printf("0\n");
	}
}