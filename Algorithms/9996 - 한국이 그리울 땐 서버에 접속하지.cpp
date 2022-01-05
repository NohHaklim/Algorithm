#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool visited[100];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	string pattern;
	cin >> pattern;

	string a, b;
	bool star = false;
	for (int i = 0; i < pattern.size(); i++)
		if (pattern[i] == '*')
		{
			star = true;
			continue;
		}
		else if (!star)
			a += pattern[i];
		else
			b += pattern[i];

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		bool answer = true;
		for (int j = 0; j < a.size(); j++)
		{
			if (s[j] != a[j])
			{
				answer = false;
				break;
			}
			visited[j] = true;
		}
		if (!answer)
		{
			cout << "NE\n";
			continue;
		}
		int idx = s.length() - 1;
		for (int j = b.size() - 1; j >= 0; j--)
		{
			if (visited[idx] || s[idx] != b[j])
			{
				answer = false;
				break;
			}
			idx--;
		}
		if (answer)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
	return 0;
}