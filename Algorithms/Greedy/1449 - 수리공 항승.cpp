#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
bool taping[1001];
int where[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		cin >> where[i];
	}

	int cnt = 0;
	sort(where, where + N + 1);
	for (int i = 1; i <= N; i++) {
		if (taping[where[i]] == false) {
			cnt++;
			taping[where[i]] = true;
			for (int j = 1; where[i] + j <= 1000 && j <= L - 1; j++) {
				taping[where[i] + j] = true;
			}
		}
	}

	cout << cnt;
}