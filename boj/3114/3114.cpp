#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C;
char grid[1500][1501][3];
int cache[1500][1500];

int noTrees(int r, int c) {
	int ret = 0;
	for (int i = 0; i < r; i++) if (grid[i][c][0] == 'B') ret++;
	for (int i = R - 1; i > r; i--) if (grid[i][c][0] == 'A') ret++;
	return ret;
}

int maxTrees(int r, int c) {
	if (r == R - 1 && c == C - 1) return 0;
	int &ret = cache[r][c];
	if (ret != -1) return ret;
	ret = max(ret, maxTrees(r + 1, c) + (grid[r][c][0] == 'B' ? grid[r][c] : 0) + (grid[r + 1][c][0] == 'A' ? -grid[r + 1][c] : 0));
	ret = max(ret, maxTrees(r, c + 1) + noTrees(r, c));
	ret = max(ret, maxTrees(r + 1, c + 1) + noTrees(r, c));
	return ret;
}

int main() {
	scanf("%d%d", &R, &C);
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			scanf("%s", grid[r][c]);
	printf("%d", maxTrees(0, 0));
}