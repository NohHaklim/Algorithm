#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string line;
	getline(cin, line);

	string temp = "";
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == '<') {
			if (!temp.empty()) {
				reverse(temp.begin(), temp.end());
				cout << temp;
				temp.clear();
			}
			while (line[i] != '>') {
				temp += line[i];
				i++;
			}
			temp += line[i];
			cout << temp;
			temp.clear();
		}
		else {
			if (line[i] != ' ') {
				temp += line[i];
			}
			else {
				reverse(temp.begin(), temp.end());
				cout << temp;
				cout << " ";
				temp.clear();
			}
		}
	}
	reverse(temp.begin(), temp.end());
	cout << temp;
}