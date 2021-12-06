#include <cstdio>
#include <stack>

using namespace std;

int main() {
	char buf[256];

	while (true) {
		bool fail = false;
		stack<char> s;
		fgets(buf, 256, stdin);
		if (buf[0] == '.') break;

		for (int i = 0; buf[i]; i++) {
			if (buf[i] == '(' || buf[i] == '[') {
				s.push(buf[i]);
			}
			else {
				if (buf[i] == ')') {
					if (s.size() > 0 && s.top() == '(') {
						s.pop();
					}
					else {
						fail = true;
					}
				}
				else if (buf[i] == ']') {
					if (s.size() > 0 && s.top() == '[') {
						s.pop();
					}
					else {
						fail = true;
					}
				}
			}
		}

		if (s.size() > 0 || fail == true) {
			printf("no\n");
		}
		else {
			printf("yes\n");
		}
	}
}