#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int cnt = 0;

	while (true)
	{
		int n0, n1;

		cnt++;
		cin >> n0;

		if (n0 == 0)
			return 0;

		n1 = 3 * n0;

		cout << cnt << ". ";
		if (n1 & 1)
		{
			cout << "odd ";
			n1 = (n1 + 1) / 2;
		}
		else
		{
			cout << "even ";
			n1 = n1 / 2;
		}
		cout << n1 * 3 / 9 << endl;
	}
}