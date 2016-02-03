#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int R, C;
char trees[1501][1502][4];
int cache[1501][1501];
int bPsum[1501][1501], aPsum[1501][1501];

int howManyTrees(char *pc) {
	int ret = 0;
	for (; *pc; pc++) ret = ret * 10 + (*pc - '0');
	return ret;
}

int howManyTrees(char type, int r, int c) {
	int ret = 0;
	if (type == 'B') {
		if (r - 1 >= 1) ret += bPsum[r - 1][c];
	} else {
		ret += aPsum[R][c] - aPsum[r][c];
	}
	return ret;
}

int maxTrees(int r, int c) {
	if (r == R && c == C) {
		return 0;
	}
	int &ret = cache[r][c];
	if (ret != -2 * INF) return ret;
	ret = -INF;
	if (c + 1 <= C) ret = max(ret, maxTrees(r, c + 1) + howManyTrees('B', r, c + 1)
													  + howManyTrees('A', r, c + 1));
	if (r + 1 <= R && c + 1 <= C) ret = max(ret, maxTrees(r + 1, c + 1) + howManyTrees('B', r + 1, c + 1)
																		+ howManyTrees('A', r + 1, c + 1));
	if (r + 1 <= R) ret = max(ret, maxTrees(r + 1, c) + (trees[r + 1][c][0] == 'B' ? 0 : -howManyTrees(trees[r + 1][c] + 1)));
	return ret;		
}

int main() {
	scanf("%d%d", &R, &C);
	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++) {
			scanf("%s", trees[r][c]);
			cache[r][c] = -(INF + INF);
		}
	for (int c = 1; c <= C; c++) {
		if (trees[1][c][0] == 'B') bPsum[1][c] = howManyTrees(trees[1][c] + 1); else aPsum[1][c] = howManyTrees(trees[1][c] + 1);
		for (int r = 2; r <= R; r++) {
			bPsum[r][c] = bPsum[r - 1][c], aPsum[r][c] = aPsum[r - 1][c];
			if (trees[r][c][0] == 'B') bPsum[r][c] += howManyTrees(trees[r][c] + 1); else aPsum[r][c] += howManyTrees(trees[r][c] + 1);
		}
	}
	printf("%d", maxTrees(1, 1) + howManyTrees('A', 1, 1));
}