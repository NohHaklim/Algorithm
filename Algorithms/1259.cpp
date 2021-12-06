/*
	1	: 0, 0
	2	: 0, 1
	3	: 0, 2 / 1, 1
	4	: 0, 3 / 1, 2
	5	: 0, 4 / 1, 3 / 2, 2
*/

#include <cstdio>

using namespace std;

char buf[7];

int main() {
	while (fgets(buf, 7, stdin)) {
		bool fail = false;

		if (buf[0] == '0') {
			break;
		}
		else {
			int size;
			for (size = 0; buf[size]; size++);
			size--;

			for (int i = 0; i < (size + 1) / 2; i++) {
				int j = size - i - 1;
				if (buf[i] != buf[j]) {
					fail = true;
				}
			}
		}
		
		if (fail == true) {
			printf("no\n");
		}
		else {
			printf("yes\n");
		}
		
	}
}