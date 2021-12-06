/*
	[lo, hi)	=> while (lo + 1 < hi)
				=> lo = mid + 1 / hi = mid - 1
				=> result = lo or hi;

	[lo, hi]	=> while (lo <= hi)
				=> lo = mid / hi = mid
				=> result = mid;

/*
2512)
hi�� 100001�� ���� ����� �ݷ�.
4
10 11 12 13
46
100000�� ����� ���... ��? 100000���� ��� 4���� ���� �� ǰ�� �� �ְŵ�.
������ �� �� �ִ� + 1�� ��ƾ� �� �� ����.

���� �ڸ��⿡���� �� 100000001���� ��Ƶ� ������?
�ڸ� ���� ���̵��� �ִ��̹Ƿ�, lo������ �۾����� �����̾�.
*/
*/

#include <cstdio>
#include <vector>

using namespace std;
typedef long long lld;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	int lo = 0, hi = 1000000000;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		lld sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid < v[i]) sum += v[i] - mid;
		}

		if (sum >= M) lo = mid;
		else hi = mid;
	}

	printf("%d", lo);
}