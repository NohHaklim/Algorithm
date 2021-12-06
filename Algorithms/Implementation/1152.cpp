/*
	띄어쓰기 다음에 문자가 나오면 1개의 단어로 친다.
	맨 처음에 띄어쓰기가 나온 다음에, 문자가 나온다면?
	prev에 ' '로 초기화한 후에 로직을 돌린다.
*/

#include <cstdio>
using namespace std;

int main() {
	int cnt = 0;
	char curr, prev = ' ';
	while ((curr = getchar()) != EOF && curr != '\n') {
		if (prev == ' ' && curr != ' ') cnt++;
		prev = curr;
	}
	printf("%d", cnt);
}