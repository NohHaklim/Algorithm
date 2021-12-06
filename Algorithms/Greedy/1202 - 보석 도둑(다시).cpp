#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int Max_num = 300000;

int N, K;
long long Sum;
pair<int, int> Items[Max_num];
int Bags[Max_num];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 제일 작은 가방에 제일 값진 거.
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> Items[i].first >> Items[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> Bags[i];
	}

	sort(Items, Items + N);
	sort(Bags, Bags + K);
	priority_queue<int> pq;
	int j = 0;
	for (int i = 0; i < K; i++) {
		while (j < N && Items[j].first <= Bags[i]) {
			pq.push(Items[j++].second);
		}

		if (!pq.empty()) {
			Sum += pq.top();
			pq.pop();
		}
	}

	cout << Sum << "\n";
}