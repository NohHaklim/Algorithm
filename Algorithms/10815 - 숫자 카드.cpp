#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vn;

bool find(int value) {
	int begin = 0, end = n - 1;

	while (begin <= end) {
		int mid = (begin + end) / 2;

		if (value < vn[mid]) {
			end = mid - 1;
		}
		else if (value > vn[mid]) {
			begin = mid + 1;
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> n;
	vn.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vn[i];
	sort(vn.begin(), vn.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int value;
		
		cin >> value;
		if (find(value))
			cout << "1 ";
		else
			cout << "0 ";
	}
}