#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int sum = 0;
	string in;
	cin >> in;
	for (int i = 0; i < in.length(); i++)
	{
		int temp;
		temp = in[i] - '0';
		temp = temp * temp * temp * temp * temp;
		sum += temp;
	}
	cout << sum;
}