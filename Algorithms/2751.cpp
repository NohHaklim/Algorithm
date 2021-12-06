#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		v.push_back(n);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		printf("%d\n", v[i]);
		
}