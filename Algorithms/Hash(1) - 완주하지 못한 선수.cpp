#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> m;
	int size = completion.size();
	for (int i = 0; i < size; i++) {
		unordered_map<string, int>::iterator iter = m.find(completion[i]);
		if (iter == m.end()) {
			m.insert({ completion[i], 1 });
		}
		else {
			iter->second++;
		}
	}

	size = participant.size();
	for (int i = 0; i < size; i++) {
		unordered_map<string, int>::iterator iter = m.find(participant[i]);
		if (iter == m.end()) {
			answer = participant[i];
			break;
		}
		else {
			if (iter->second != 0) {
				iter->second--;
			}
			else {
				answer = iter->first;
				break;
			}
		}
	}

	return answer;
}