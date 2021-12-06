#include <iostream>
using namespace std;

int n;
const int MAX = 100000 + 1;
int inOrder[MAX], postOrder[MAX], idx[MAX];

void preOrder(int inS, int inE, int postS, int postE) {
	if (inS > inE || postS > postE)
		return;

	int root = postOrder[postE];
	cout << postOrder[postE] << " ";
	preOrder(inS, idx[root] - 1, postS, postS + (idx[root] - inS) - 1);
	preOrder(idx[root] + 1, inE, postS + (idx[root] - inS), postE - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> inOrder[i];
	for (int i = 1; i <= n; i++)
		cin >> postOrder[i];
	for (int i = 1; i <= n; i++)
		idx[inOrder[i]] = i;
	preOrder(1, n, 1, n);
}