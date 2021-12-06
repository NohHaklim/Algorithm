#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int F[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, value;
	cin >> n;
	
	vector<int>v(n);
	queue<pair<int, int>> q;
	stack<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		cin >> value;
		F[value]++;
		q.push({ value, i });
	}

	while (!q.empty()) {
		int value = q.front().first, idx = q.front().second;
		q.pop();

		while (!s.empty()) {
			if (F[s.top().first] < F[value]) {
				v[s.top().second] = value;
				s.pop();
			}
			else
				break;
		}
		s.push({ value, idx });
	}

	while (!s.empty()) {
		v[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}