#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int num = 0, cnt = 0, temp = n;
	while (temp)
	{
		num++;
		if (temp - num < 0)
			num = 0;
		else
		{
			temp -= num;
			cnt++;
		}
	}
	cout << cnt;
}