#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	stack<pair<int, int>> s;
	vector<int> v;
	
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		
		while (!s.empty()) {
			if (s.top().first < value) {
				v[s.top().second] = value;
				s.pop();
			}
			else
				break;
		}
		s.push({ value, i });
	}

	while (!s.empty()) {
		v[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}