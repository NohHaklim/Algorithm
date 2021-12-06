#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	stack<int> s;

	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		
		if (v == 0) {
			s.pop();
		}
		else {
			s.push(v);
		}
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	printf("%d", sum);
}