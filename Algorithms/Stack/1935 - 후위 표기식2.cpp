#include <iostream>
#include <string>
#include <stack>
using namespace std;

double g_table[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	string cmd;
	stack<double> s_num;

	cin >> n; cin.ignore();
	getline(cin, cmd);
	for (int i = 0; i < n; i++) {
		cin >> g_table[i];
	}

	for (int i = 0; i < cmd.length(); i++) {
		int type;

		if ('A' <= cmd[i] && cmd[i] <= 'Z') {
			s_num.push(g_table[cmd[i] - 'A']);
		}
		else {
			double a, b;
			b = s_num.top(); s_num.pop();
			a = s_num.top(); s_num.pop();

			switch (cmd[i]) {
			case '+':
				s_num.push(a + b);
				break;
			case '-':
				s_num.push(a - b);
				break;
			case '*':
				s_num.push(a * b);
				break;
			case '/':
				s_num.push(a / b);
				break;
			}
		}
	}

	double ret = s_num.top();
	s_num.pop();
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << ret;
}