#include <cstdio>
#include <unordered_map>
using namespace std;

/*
	1. 첫 번째 입력으로 들어오는 N개의 수를 unordered_map에 저장한다.
		이 때, 수(key):갯수(value)로 저장한다.
	2. 두 번째 입력으로 들어오는 M개의 수를 unordered_map에서 탐색한다.
		이 때, 그 수의 갯수를 출력한다.
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