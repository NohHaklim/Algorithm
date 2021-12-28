#include <iostream>
#include <queue>
using namespace std;

bool is_prime(int nb)
{
	int i;

	if (nb < 2)
		return false;
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return false;
		i++;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int digit;
	queue<int> q;

	cin >> digit;
	q.push(0);
	for (int i = 0; i < digit; i++)
	{
		int size = q.size();
		for (int j = 0; j < size; j++)
		{
			int nb = q.front();
			q.pop();
			for (int k = 1; k <= 9; k++)
			{
				int temp = nb * 10 + k;
				if (is_prime(temp))
					q.push(temp);
			}
		}
	}
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}