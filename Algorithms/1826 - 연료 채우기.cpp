#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, dest, remain, ret;
// gasStation[거리][채울 수 있는 기름의 양]
typedef pair<int, int> pii;
vector<pii> gasStation;

struct cmp
{
	bool operator()(pii &a, pii &b)
	{
		if (a.second == b.second)
			return a.first > b.first;
		else
			return a.second < b.second;
	}
};

priority_queue<pii, vector<pii>, cmp> pq;

int solve(int pos, int idx)
{
	int i;

	if (pos + remain >= dest)
		return ret;
	for (i = idx; i < gasStation.size(); i++)
	{
		if (remain >= gasStation[i].first - pos)
			pq.push(gasStation[i]);
		else
			break;
	}
	if (pq.empty())
		return -1;
	ret++;
	if (pos < pq.top().first)
	{
		remain += pq.top().second - (pq.top().first - pos);
		pos = pq.top().first;
	}
	else
		remain += pq.top().second;
	pq.pop();
	return solve(pos, i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		gasStation.push_back({ a, b });
	}
	cin >> dest >> remain;
	sort(gasStation.begin(), gasStation.end());
	cout << solve(0, 0);
}