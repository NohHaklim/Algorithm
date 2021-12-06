#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, value, max_value;
		char buf[21], max_buf[21];
		
		scanf("%d", &n);
		scanf("%d %s", &max_value, max_buf);
		for (int i = 1; i < n; i++) {
			scanf("%d %s", &value, buf);
			if (max_value < value) {
				max_value = value;
				strcpy(max_buf, buf);
			}
		}
		printf("%s\n", max_buf);
	}
}