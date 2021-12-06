#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	int size = commands.size();
	for (int a = 0; a < size; a++) {
		vector<int> command = commands[a];
		int i, j, k;
		i = command[0]; j = command[1]; k = command[2];

		vector<int> temp;
		int size = j - i + 1;
		for (int b = 0; b < size; b++)
			temp.push_back(array[i - 1 + b]);

		sort(temp.begin(), temp.end());
		answer.push_back(temp[k - 1]);
	}

	return answer;
}