/*
	ī���� ����
	������ ������ ��û ������, �� ���� ������ ���� ��� �� �� �ִ� ���Ĺ�
*/

#include <cstdio>
using namespace std;

int arr[10001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (arr[i]) {
			printf("%d\n", i);
			arr[i]--;
		}
	}
}