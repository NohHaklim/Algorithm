#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> V;

bool comp(const string &a, const string &b) {
	int min_len = min(a.length(), b.length());

	int idx;
	for (idx = 0; idx < min_len; idx++) {
		if (a[idx] != b[idx])
			return a[idx] < b[idx];
	}

	if (a.length() > b.length()) {
		return a[min_len] < b[0];
	}
	else {
		return b[min_len] < a[0];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	V.resize(N);
	for (int i = 0; i < N; i++)
		cin >> V[i];

	sort(V.begin(), V.end(), comp);

	for (int i = 0; i < N; i++)
		cout << V[i];
}