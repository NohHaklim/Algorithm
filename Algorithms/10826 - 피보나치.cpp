#include <iostream>
#include <string>

using namespace std;

string add(string s1, string s2) {
	string res(s1.size() > s2.size() ? s1.size() : s2.size(), '0');
	bool carry = false;

	for (int i = 0; i < res.size(); i++) {
		int temp = carry;
		carry = false;

		if (s1.size() > i) temp += (s1[s1.size() - i - 1] - '0');
		if (s2.size() > i) temp += (s2[s2.size() - i - 1] - '0');
		if (temp >= 10) {
			carry = true;
			temp -= 10;
		}

		res[res.size() - i - 1] = temp + '0';
	}
	
	if (carry) {
		res = "1" + res;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	
	string a = "0", b = "1", res;
	if (n == 0) {
		cout << "0";
	}
	else if (n == 1) {
		cout << "1";
	}
	else {
		for (int i = 0; i <= n - 2; i++) {
			res = add(a, b);
			a = b;
			b = res;
		}
	}

	cout << res;
}