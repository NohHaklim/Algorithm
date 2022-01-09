#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string number;
	int num_set[9] = { 0 }, cnt = 0, set_cnt = 0;
	
	cin >> number;
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] == '6' || number[i] == '9')
		{
			num_set[6]++;
			cnt++;
			continue;
		}
		num_set[number[i] - '0']++;
		cnt++;
	}
	
	while (cnt)
	{
		set_cnt++;
		for (int i = 0; i < 9; i++)
		{
			if (num_set[i])
			{
				num_set[i]--;
				cnt--;
			}
		}
		if (num_set[6])
		{
			num_set[6]--;
			cnt--;
		}
	}
	cout << set_cnt;
}