// ac
#include <cstdio>
#include <algorithm>
using namespace std;
int d[] = {0, 0, -1, 1};
int main() {
	int r, c;
	char grid[15][15] = {{0}};
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) scanf("%s", grid[i] + 1);
	for (int i = 0; i <= r+1; i++) grid[i][0] = grid[i][c+1] = '.';
	for (int j = 0; j <= c+1; j++) grid[0][j] = grid[r+1][j] = '.';
	bool chk[15][15] = {{0}};
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (grid[i][j] == 'X') {
				int neighbor = 0;
				for (int k = 0; k < 4; k++) {
					int ii = i + d[k], jj = j + d[(k + 2) % 4];
					if (grid[ii][jj] == '.') neighbor++;
				}
				if (neighbor >= 3) chk[i][j] = 1;
			}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (chk[i][j]) grid[i][j] = '.';
	int xmin, ymin, xmax, ymax;
	xmin = ymin = 15;
	xmax = ymax = -1;
	for (int i = 0; i <= r+1; i++)
		for (int j = 0; j <= c+1; j++)
			if (grid[i][j] == 'X') {
				xmin = min(xmin, j);
				ymin = min(ymin, i);
				xmax = max(xmax, j);
				ymax = max(ymax, i);
			}
	for (int i = ymin; i <= ymax; i++) {
		for (int j = xmin; j <= xmax; j++) putchar(grid[i][j]);
		putchar('\n');
	}
}