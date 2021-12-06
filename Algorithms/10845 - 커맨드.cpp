#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int ctoi(char *tok) {
	int res = 0;
	for (int i = 0; tok[i];) {
		res = res + tok[i] - '0';
		if (tok[++i]) res *= 10;
	}
	return res;
}

int main() {
	char cmd[256] = { '\0' };
	queue<int> q;
	int n;

	scanf("%d", &n); getchar();
	while (n--) {
		fgets(cmd, 256, stdin);
		
		char *temp = strdup(cmd);
		char *tok1 = strtok(temp, " \n");
		char *tok2 = strtok(NULL, " \n");

		if (strcmp(tok1, "push") == 0) {
			int value = ctoi(tok2);
			q.push(value);
		}
		else if (strcmp(tok1, "pop") == 0) {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				int value = q.front();
				q.pop();
				printf("%d\n", value);
			}
		}
		else if (strcmp(tok1, "size") == 0) {
			printf("%d\n", q.size());
		}
		else if (strcmp(tok1, "empty") == 0) {
			if (q.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(tok1, "front") == 0) {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.front());
			}
		}
		else if (strcmp(tok1, "back") == 0) {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.back());
			}
		}
	}
}