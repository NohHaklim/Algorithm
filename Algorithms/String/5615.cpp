#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Member {
public:
	string name;
	int d, m, y;
};

bool compare(Member a, Member b) {
	if (a.y != b.y) {
		return a.y > b.y;
	}
	else {
		if (a.m != b.m) {
			return a.m > b.m;
		}
		else {
			return a.d > b.d;
		}
	}
}

int main() {
	int N;
	vector<Member> v;

	cin >> N;
	while (N--) {
		Member *m = new Member();
		cin >> m->name >> m->d >> m->m >> m->y;

		v.push_back(*m);
	}
	sort(v.begin(), v.end(), compare);

	cout << v.begin()->name << endl << v.rbegin()->name;
}