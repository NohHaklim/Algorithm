#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	string str_a = to_string(a);
	string str_b = to_string(b);

	string A = str_a + str_b;
	string B = str_b + str_a;

	return stoi(A) > stoi(B);
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), compare);

	

	int size = numbers.size();
	for (int i = 0; i < size; i++) {
		answer += to_string(numbers[i]);
	}

	if (numbers[0] == 0)
		answer = "0";

	return answer;
}