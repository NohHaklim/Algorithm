/*
	)�� ������ ������ (�� stack�� ���ٸ�?
	�ùٸ��� ����.
*/

#include <cstdio>
#include <stack>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	getchar();
	while (n--) {
		stack<char> s;
		char in;
		bool fail = false;
		while ((in = getchar()) != EOF && in != '\n') {
			if (in == '(') s.push(in);
			else {
				if (s.size() != 0 && s.top() == '(') {
					s.pop();
				}
				else {
					fail = true;
				}
			}
		}
		if (s.size() != 0 || fail == true) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
}