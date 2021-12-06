/*
	Arr		: 10 20 40 25 20 50 30 70 60
	Vector	: 10 20 40
			        25
				 20    50
				       30 70
					      60

	vector.back()���� �迭�� ���� �� ũ�ٸ�, vector�� �ִ´�.
	���� ������ ���� �� �۴ٸ�, vector ������ lower_bound ��ġ�� �ִ´�.
		=> vector �� �߰��� ���� �ٲ����, ��������� LIS �� ���� ū ���� ������ �ʴ´�.
		=> ���� �� ������ ���� �ʴ´�.
	vector�� ������ ���� LIS ���� �������.
		=> �� �˰����� ������ LIS�� ���̿� LIS �� ���� ū ���� �����ȴٴ� ���̴�.
	vector�� ���̴� LIS�� �����̴�.

	lower_bound ��?
		- ����Ž�� ���
		- key������ ũ�ų� ���� ������ ��ġ ����
		- ���ĵ� ���¿��� �Ѵ�.
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