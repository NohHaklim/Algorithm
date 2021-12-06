#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int kor, eng, math;

	bool operator < (const Student& that) {
		if (this->kor != that.kor) {
			return this->kor > that.kor;
		}
		else if (this->eng != that.eng) {
			return this->eng < that.eng;
		}
		else if (this->math != that.math) {
			return this->math > that.math;
		}
		else {
			return this->name < that.name;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<Student> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i].name << "\n";
	}
}