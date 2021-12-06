/*
	Arr		: 10 20 40 25 20 50 30 70 60
	Vector	: 10 20 40
			        25
				 20    50
				       30 70
					      60

	vector.back()보다 배열의 수가 더 크다면, vector에 넣는다.
	만약 수열의 수가 더 작다면, vector 내에서 lower_bound 위치에 넣는다.
		=> vector 내 중간의 값이 바뀌더라도, 현재까지의 LIS 내 가장 큰 수는 변하지 않는다.
		=> 따라서 별 영향을 주지 않는다.
	vector의 값들은 실제 LIS 값과 상관없다.
		=> 이 알고리즘의 요점은 LIS의 길이와 LIS 내 가장 큰 값이 유지된다는 점이다.
	vector의 길이는 LIS의 길이이다.

	lower_bound 란?
		- 이진탐색 기법
		- key값보다 크거나 같은 최초의 위치 리턴
		- 정렬된 상태여야 한다.
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n, temp;
	scanf("%d", &n);

	v.push_back(0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		
		if (v.back() < temp) {
			v.push_back(temp);
		}
		else {
			vector<int>::iterator iter = lower_bound(v.begin(), v.end(), temp);
			*iter = temp;
		}
	}

	printf("%d", v.size() - 1);
}