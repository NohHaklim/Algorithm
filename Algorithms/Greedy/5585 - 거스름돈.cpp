#include <iostream>
#include <vector>
using namespace std;

int solve(int money) {
	int cnt = 0;

	cnt += (money / 500);
	money = money % 500;

	cnt += (money / 100);
	money = money % 100;

	cnt += (money / 50);
	money = money % 50;

	cnt += (money / 10);
	money = money % 10;

	cnt += (money / 5);
	money = money % 5;

	cnt += (money / 1);
	money = money % 1;

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int money;
	cin >> money;
	money = 1000 - money;

	cout << solve(money);
}