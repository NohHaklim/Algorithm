#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K, Cnt;
vector<string> V(10);

void solution(string base) {
	string temp = base;
	int cnt = 0;
	int len = base.length();

	temp += temp;
	for (int j = 0; j < base.length(); j++) {
		if (base == temp.substr(j, len)) {
			cnt++;
		}
		if (cnt > K)
			break;
	}
	if (cnt == K) {
		Cnt++;
	}
}

void permutate(int idx, int used ,string base) {
	if (idx == N) {
		solution(base);
	}

	for (int i = 0; i < N; i++) {
		if (used & (1 << i))
			continue;
		permutate(idx + 1, used | (1 << i), base + V[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	cin >> K;

	permutate(0, 0, "");

	cout << Cnt;
}