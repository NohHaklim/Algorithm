#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		string temp;

		getline(cin, temp, '\n');
		
		int from = 0, to = 0;
		while (to < temp.length()) {
			while (to < temp.length() && temp[to] != ' ') {
				to++;
			}
			for (int i = to - 1; i >= from; i--) {
				cout << temp[i];
			}
			if (to < temp.length())
				cout << temp[to];
			else
				cout << "\n";
			from = ++to;
		}
	}
}