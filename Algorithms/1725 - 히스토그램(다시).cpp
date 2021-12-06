#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100000];

int solve(int start, int end) {
	if (start == end) return 0;	// start == end == N�� ���
	if (start + 1 == end) return arr[start];

	int mid = (start + end) / 2;
	// ���� ���� ���� �ִ�
	int result = max(solve(start, mid), solve(mid, end));

	int width = 1, height = arr[mid], left = mid, right = mid;
	while (right - left + 1 < end - start) {
		int p = left > start ? min(height, arr[left - 1]) : -1; // ���� Ȯ�� ����
		int q = right < end - 1 ? min(height, arr[right + 1]) : -1; // ������ Ȯ�� ����
		// �� ���� ������ Ȯ��
		if (p >= q) {
			height = p;
			left--;
		}
		else {
			height = q;
			right++;
		}
		result = max(result, ++width* height);
	}
	return result;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d", solve(0, N));
}