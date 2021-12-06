#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n, max = -4001, min = 4001;
	double sum = 0;
	scanf("%d", &n);
	vector<int> v(n);
	int flag[8001] = { 0 };

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		sum += v[i];
		flag[v[i] + 4000]++;
		if (max < v[i]) max = v[i];
		if (min > v[i]) min = v[i];
	}

	sort(v.begin(), v.end());

	sum /= n;
	printf("%.0lf\n", floor(sum + 0.5));		// 반올림
	printf("%d\n", v[n / 2]);					// 중앙값

	bool find = false;
	int most = 0;
	for (int i = 1; i <= 8000; i++) {
		if (flag[most] < flag[i]) {
			most = i;
			find = false;
		}
		else if (find == false && flag[most] == flag[i]) {
			most = i;
			find = true;
		}
	}
	
	printf("%d\n", most - 4000);
	printf("%d\n", max - min);
}