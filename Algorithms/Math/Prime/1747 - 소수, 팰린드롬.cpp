#include <iostream>
#include <string>
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

int find_next_prime(int nb)
{
	while (!is_prime(nb))
		nb++;
	return nb;
}

bool is_palindrome(int nb)
{
	string n = to_string(nb);
	int l = 0, r = n.length() - 1;

	while (l < r)
	{
		if (n[l] != n[r])
			return false;
		l++;
		r--;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int nb;

	cin >> nb;
	while (true)
	{
		int nextPrime = find_next_prime(nb);

		if (is_palindrome(nextPrime))
		{
			cout << nextPrime;
			return 0;
		}
		else
			nb = nextPrime + 1;
	}
}