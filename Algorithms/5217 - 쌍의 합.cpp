#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		bool type = false;
		cin >> n;

		cout << "Pairs for " << n << ":";
		for (int i = 1; i <= n / 2; i++)
		{
			int j = n - i;
			if (i == j)
				continue;
			if (type)
				cout << ",";
			cout << " ";
			cout << i << " " << j;
			type = true;
		}
		cout << endl;
	}
}