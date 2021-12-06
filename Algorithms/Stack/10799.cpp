#include <cstdio>
#include <stack>
using namespace std;

int main() {
	int cnt = 0;
	char c, prev = '\0';
	stack<char> s;

	while ((c = getchar()) != '\n' && c != EOF) {
		if (c == '(') {
			s.push(c);
		}
		else {
			s.pop();
			if (prev == '(') {
				cnt += s.size();
			}
			else {
				cnt += 1;
			}
		}
		prev = c;
	}

	printf("%d", cnt);
}