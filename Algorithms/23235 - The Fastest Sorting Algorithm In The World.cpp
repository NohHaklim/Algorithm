#include <iostream>
using namespace std;

int arr[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cnt = 0;
	while (true)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
			return 0;
		cnt++;
		for (int i = 0; i < temp; i++)
			cin >> arr[i];
		cout << "Case " << cnt << ": Sorting... done!\n";
	}
}