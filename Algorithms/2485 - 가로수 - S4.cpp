/**
		가로수의 위치가 입력으로 들어온다.
		가로수들이 모두 같은 간격이 되어야 한다.
		그렇다면, 입력받은 가로수 간격이 가장 작은 값을 구해서
		나머지들이 그 간격만큼 되도록 조정하면 되겠네?

		만약 1 3 8 이라면...?
		가장 작은 간격이 2니까 5에 심고, 7에 심으면 간격이 1이 돼버리는데...?
		1 3 5 7 8 이 돼버려....
		그럼 또 가장 작은 간격이 1이니까 1 2 3 4 5 6 7 8이 되고...
		최소수는 5가 돼버리네..??

		1 3 7 13
		5 9 11 심으면 되니까 최소수는 3.

		1 3 8 이라면, 간격이 2와 5니까 최대 공약수가 1이야. 1로 만들어야하네...?
		1 3 7 13 이라면, 간격이 2 4, 6이니까 최대공약수 2로 만들 수 있는거야!


		* 유클리드 호제법
		f(a, b) = gcd(a, b), 이 때 a mod b = 0 이라면 f(a, b) = b이다.
		만약 a mod b != 0 이라면 f(a, b) = f(b, a mod b)가 성립한다.

**/

#include <cstdio>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	int mod = a % b;
	while (mod > 0) {
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}

int main() {
	int N, g, res = 0;
	scanf("%d", &N);
	vector<int> v(N);
	scanf("%d %d", &v[0], &v[1]);
	
	g = v[1] - v[0];
	for (int i = 2; i < N; i++) {
		scanf("%d", &v[i]);
		g = gcd(g, v[i] - v[i - 1]);
	}

	for (int i = 1; i < N; i++) {
		res = res + ((v[i] - v[i - 1]) / g) - 1;
	}
	printf("%d", res);
}