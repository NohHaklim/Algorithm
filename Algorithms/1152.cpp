/*
	���� ������ ���ڰ� ������ 1���� �ܾ�� ģ��.
	�� ó���� ���Ⱑ ���� ������, ���ڰ� ���´ٸ�?
	prev�� ' '�� �ʱ�ȭ�� �Ŀ� ������ ������.
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