#include <iostream>
using namespace std;

int n, m, sum_of_weight;
int weight[31];
int marble[8];
bool dp[31][40001] = { false };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	/*
			무게	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
		구슬
			1(7)							Y
			2(8)	Y						Y	Y							Y
			3(9)	Y	Y				Y	Y	Y	Y	Y					Y	Y

		구슬을 오름차순 정렬하고,
		DP[i][j] = i번 까지의 구슬을 사용해서 j 무게 측정이 가능한가.

		DP[i][j] true
		if (DP[i - 1][j])
			if (j + weight[i] <= 50000)
				DP[i][j + weight[i]] true
			if (weight[i] - j > 0)
				DP[i][weight[i] - j] true
	*/
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		sum_of_weight += weight[i];
	}
		
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> marble[i];

	for (int i = 1; i <= n; i++) {
		if (weight[i] <= sum_of_weight)
			dp[i][weight[i]] = true;
		for (int j = 1; j <= sum_of_weight; j++) {
			if (dp[i - 1][j]) {
				dp[i][j] = true;
				if (j + weight[i] <= sum_of_weight)
					dp[i][j + weight[i]] = true;
				if (weight[i] - j > 0)
					dp[i][weight[i] - j] = true;
				if (j - weight[i] > 0)
					dp[i][j - weight[i]] = true;
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		if (dp[n][marble[i]])
			cout << "Y ";
		else
			cout << "N ";
	}
}