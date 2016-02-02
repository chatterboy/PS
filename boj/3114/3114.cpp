#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int R, C;
char trees[1501][1502][4];
int cache[1501][1501];

int howManyTrees(char *pc) {
	int ret = 0;
	for (; *pc; pc++) ret = ret * 10 + (*pc - '0');
	return ret;
}

int howManyTrees(char type, int r, int c) {
	int ret = 0;
	if (type == 'B') {
		for (int i = r - 1; i >= 1; i--) if (trees[i][c][0] == type)
			ret += howManyTrees(trees[i][c] + 1);
	} else {
		for (int i = r + 1; i <= R; i++) if (trees[i][c][0] == type)
			ret += howManyTrees(trees[i][c] + 1);
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
	printf("%d", maxTrees(1, 1) + howManyTrees('A', 1, 1));
}