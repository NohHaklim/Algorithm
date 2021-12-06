#include <cstdio>

using namespace std;

int map[101][101];

int main()
{	
	for (int i = 0; i < 4; i++) {
		int x1, x2;
		int y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				map[x][y]++;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j])
				sum++;
		}
	}
	printf("%d\n", sum);
}