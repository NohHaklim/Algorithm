#include <cstdio>
#include <unordered_map>
using namespace std;

/*
	1. ù ��° �Է����� ������ N���� ���� unordered_map�� �����Ѵ�.
		�� ��, ��(key):����(value)�� �����Ѵ�.
	2. �� ��° �Է����� ������ M���� ���� unordered_map���� Ž���Ѵ�.
		�� ��, �� ���� ������ ����Ѵ�.
*/

unordered_map<int, int> h;
int main() {
	int N, M;
	unordered_map<int, int>::iterator iter;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		
		iter = h.find(temp);
		if (iter == h.end())
			h.insert(unordered_map<int, int>::value_type(temp, 1));
		else
			iter->second++;
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);

		iter = h.find(temp);
		if (iter == h.end())
			printf("0 ");
		else
			printf("%d ", iter->second);
	}

	return 1;
}