#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;
int sudoku[MAX][MAX];
bool row[MAX][MAX + 1]; //열, 1~9
bool col[MAX][MAX + 1]; //행, 1~9
bool square[MAX][MAX + 1]; //3*3 박스 idx, 1~9

int change2SquareIdx(int y, int x) {
	return (y / 3) * 3 + x / 3;
}

void solve(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++)
				cout << sudoku[i][j] << " ";
			cout << endl;
		}
		exit(0);
	}
	int y = cnt / 9;
	int x = cnt % 9;

	if (sudoku[y][x])
		solve(cnt + 1);

	else {
		for (int k = 1; k <= MAX; k++) {
			if (!col[x][k] && !row[y][k] && !square[change2SquareIdx(y, x)][k]) {
				sudoku[y][x] = k;
				col[x][k] = true;
				row[y][k] = true;
				square[change2SquareIdx(y, x)][k] = true;

				solve(cnt + 1);

				sudoku[y][x] = 0;
				col[x][k] = false;
				row[y][k] = false;
				square[change2SquareIdx(y, x)][k] = false;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j]) {
				col[j][sudoku[i][j]] = true;
				row[i][sudoku[i][j]] = true;
				square[change2SquareIdx(i, j)][sudoku[i][j]] = true;
			}
		}
	}
	solve(0);
}