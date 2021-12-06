/*
	���� ������ -2^62 ~ 2^62 �� ī������ �ȵ�...
	100000���� ī�带 �� ����ؼ�
	������ ���� ī����?

	���� ���� ������ �ִ� ������ ���ϴ°��ڳ�...
	������ �ϰ���, �տ������� ���������� üŷ => nlogn + n���� ���� ����

	��� üŷ�� �ϴ°�?
	1...i, (i + 1), ...n �� ��, arr[i]�� arr[i + 1]�� ���ٸ� cnt++;
	���� �ٸ��ٸ� res �� cnt + 1�� ���� ���ٸ�? cnt + 1�� ī������ ������ � ����
	res�� ����� ī������ ������ � ������ Ŭ ���̹Ƿ� res�� ����.
	�׷��� �ʴٸ� res = max(res, cnt + 1)
	�׸��� cnt �ʱ�ȭ

	=> '�׷��� �ʴٸ�' �� �κп��� error ��? arr[n - 2]�� arr[n - 1] ���ؼ�
	cnt�� �������״µ�, �̰� max_cnt���� Ŭ ��츦 ��Ʈ�� ����.
	��... ���ĵ� vector�� �������� 0�� ����ְ�...

	�������ε� Ǯ �� �ֱ� �ϳ�. �ٵ� �̰� �ð� �� ���� ��ƸԳ�?

int main() {
	int t;
	ll key;
	int cnt;
	scanf("%d", &t);

	map <ll, int> m;
	map <ll, int>::iterator iter;
	for (int i = 0; i < t; i++) {
		scanf("%lld", &key);
		if (m[key] == 0) {		// ã�� ���� ���ٸ�,
			cnt = 1;
		}
		else {
			cnt = m[key] + 1;
		}
		m[key] = cnt;
	}
	key = m.begin()->first;
	cnt = m.begin()->second;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > cnt) {
			cnt = iter->second;
			key = iter->first;
		}
	}
	printf("%lld", key);
}
	�Ƹ� key���� ã�� �� ������ �׷� �� ����. ������ ���� ���ĵ� �Ŷ�
*/

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long lld;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<lld> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int cnt = 1, max_cnt = 1;
	lld res = v[0];
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		if (v[i] == v[i + 1]) {
			cnt++;
		}
		else {
			if (max_cnt < cnt) {
				max_cnt = cnt;
				res = v[i];
			}
			cnt = 1;
		}
	}
	cout << res;
}