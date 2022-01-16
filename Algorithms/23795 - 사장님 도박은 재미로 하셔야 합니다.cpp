#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int sum = 0, temp;
	while (true)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
			break;
		sum += temp;
	}
	cout << sum;
}