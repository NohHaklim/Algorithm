#include <iostream>
#include <vector>
using namespace std;

int N, M;
int Sum, Min;
bool Flag;

bool isPrime(int n) {
	if (n < 2)
		return false;
	if (n != 2 && n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = N; i <= M; i++) {
		if (isPrime(i)) {
			Sum += i;
			if (Flag == false) {
				Min = i;
				Flag = true;
			}
		}
	}

	if (Sum == 0)
		cout << "-1";
	else
		cout << Sum << endl << Min;
}