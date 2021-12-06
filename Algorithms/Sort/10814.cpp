#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
	int age;
	string name;
	int num;

	bool operator < (const Student& s) {
		if (this->age != s.age) {
			return this->age < s.age;
		}
		else {
			return this->num < s.num;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<Student> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].age >> v[i].name;
		v[i].num = i;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i].age << " " << v[i].name << "\n";
	}
}