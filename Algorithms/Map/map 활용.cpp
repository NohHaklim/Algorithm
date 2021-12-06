#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> foodMaps[11];
int maxCnt[11] = { 0 };

void comb(string str, int pos, string cand) {
	if (pos == str.length()) {
		int len = cand.length();
		if (len >= 2) {
			foodMaps[len][cand]++;
			maxCnt[len] = max(maxCnt[len], foodMaps[len][cand]);
		}
		return;
	}
	comb(str, pos + 1, cand + str[pos]);
	comb(str, pos + 1, cand);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	for (string str : orders) {
		sort(str.begin(), str.end());
		comb(str, 0, "");
	}

	vector<string> answer;
	for (int len : course) {
		for (auto item : foodMaps[len]) {
			if (item.second >= 2 && item.second == maxCnt[len]) {
				answer.push_back(item.first);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}