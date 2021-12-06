#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int num = 1;

	while (true)
	{
		int L, P, V, cnt;
		
		cin >> L >> P >> V;

		if (L == P && P == V && L == 0)
			return 0;

		cnt = V / P * L;
		cnt = cnt + (V % P <= L ? V % P : L);

		cout << "Case " << num++ << ": " << cnt << "\n";
	}
}