#include <cstdio>
#include <vector>
using namespace std;

long long N;
vector <bool> b;

int main() {
	scanf("%lld", &N);
	
	do {
		if (N & 1 == 1) b.push_back(true);
		else b.push_back(false);
		N >>= 1;
	} while (N > 0);

	while (!b.empty()) {
		bool flag = b.back();
		b.pop_back();
		if (flag) printf("1");
		else printf("0");
	}
}