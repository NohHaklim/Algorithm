#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, L, idx = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	vector<int> v;

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		pq.push({ i, num });

		while (pq.top().first < i - L + 1)
			pq.pop();

		cout << pq.top().second << " ";
	}
}