/*
	수의 범위가 -2^62 ~ 2^62 라서 카운팅은 안됨...
	100000개의 카드를 다 기록해서
	일일이 갯수 카운팅?

	가장 많이 가지고 있는 정수를 구하는거자나...
	정렬을 하고나서, 앞에서부터 선형적으로 체킹 => nlogn + n으로 거의 선형

	어떻게 체킹을 하는가?
	1...i, (i + 1), ...n 일 때, arr[i]와 arr[i + 1]이 같다면 cnt++;
	만약 다르다면 res 와 cnt + 1의 값이 같다면? cnt + 1의 카운팅을 가지는 어떤 수는
	res에 저장된 카운팅을 가지는 어떤 수보다 클 것이므로 res를 유지.
	그렇지 않다면 res = max(res, cnt + 1)
	그리고 cnt 초기화

	=> '그렇지 않다면' 이 부분에서 error 왜? arr[n - 2]와 arr[n - 1] 비교해서
	cnt를 증가시켰는데, 이게 max_cnt보다 클 경우를 컨트롤 못함.
	음... 정렬된 vector의 마지막에 0을 집어넣고...

	맵핑으로도 풀 수 있긴 하네. 근데 이건 시간 좀 많이 잡아먹네?

int main() {
	int t;
	ll key;
	int cnt;
	scanf("%d", &t);

	map <ll, int> m;
	map <ll, int>::iterator iter;
	for (int i = 0; i < t; i++) {
		scanf("%lld", &key);
		if (m[key] == 0) {		// 찾는 값이 없다면,
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
	아마 key값을 찾는 것 때문에 그럴 거 같음. 맵핑이 이진 정렬된 거라
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