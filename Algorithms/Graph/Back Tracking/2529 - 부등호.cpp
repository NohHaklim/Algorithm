#include <iostream>
#include <string>
#include <vector>

#define LEFT false
#define RIGHT true
#define MAX 0
#define MIN 1

using namespace std;

int N;
string Num;
bool Check[10];
bool Comp[9];
long long Min = 9976543210;
long long Max = -1;
string Answer[2];

void solution(int pos) {
	
	if (pos == N) {
		long long nb = stoll(Num);
		
		if (Max < nb) {
			Max = nb;
			Answer[MAX] = Num;
		}
		if (Min > nb) {
			Min = nb;
			Answer[MIN] = Num;
		}
		return;
	}

	int from, to;
	if (Comp[pos] == LEFT) {
		from = 0;
		to = Num.back() - '0';
	}
	else {
		from = Num.back() -'0' + 1;
		to = 10;
	}

	for (int i = from; i < to; i++) {
		if (!Check[i]) {
			if (Comp[pos] == LEFT) {
				if (Num.back() - '0' < i)
					continue;
			}
			else {
				if (Num.back() - '0' > i)
					continue;
			}

			Check[i] = true;
			Num.push_back(i + '0');

			solution(pos + 1);

			Check[i] = false;
			Num.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		if (temp == '>') {
			Comp[i] = LEFT;
		}
		else
			Comp[i] = RIGHT;
	}

	for (int num = 0; num < 10; num++) {
		if (!Check[num]) {
			Check[num] = true;
			Num.push_back(num + '0');

			solution(0);

			Check[num] = false;
			Num.pop_back();
		}
	}

	cout << Answer[MAX] << "\n" << Answer[MIN];
}