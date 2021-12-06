#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> V;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	V.resize(N);
	for (int i = 0; i < N; i++)
		cin >> V[i];

	int idx = N - 1;
	while (idx > 0 && V[idx - 1] >= V[idx])
		idx--;

	if (idx == 0)
	{
		cout << "-1\n";
		return 0;
	}

	int idx2 = N - 1;
	while (V[idx - 1] >= V[idx2])
		idx2--;

	swap(V[idx - 1], V[idx2]);
	idx2 = N - 1;
	while (idx < idx2) {
		swap(V[idx], V[idx2]);
		idx++;
		idx2--;
	}

	for (int i = 0; i < N; i++)
		cout << V[i] << " ";
	cout << "\n";
	return 0;

}