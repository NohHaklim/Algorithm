#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;
	while (!str1.empty() && !str2.empty())
	{
		
		if (str1.back() == str2.back())
		{
			str1.pop_back();
			str2.pop_back();
		}
		else
		{
			if ('0' <= str1.back() && str1.back() <= '9')
			{
				str1.pop_back();
				continue;
			}
			cout << "0";
			return 0;
		}
	}
	
	if (str2.empty())
		cout << "1";
}