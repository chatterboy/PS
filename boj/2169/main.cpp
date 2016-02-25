#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;

int N, M;
vector<vector<int>> grid;
int cache[1000][1000][3];

int solve(int y, int x, int state) {
	if (y < 0 || y >= N || x < 0 || x >= M) return -inf;
	if (y == N - 1 && x == M - 1) return grid[y][x];
	int &ret = cache[y][x][state];
	if (ret != -2 * inf) return ret;
	ret = -inf;
	if (state == 0) {
		ret = max(ret, solve(y + 1, x, state) + grid[y][x]);
		ret = max(ret, solve(y, x - 1, 1) + grid[y][x]);
		ret = max(ret, solve(y, x + 1, 2) + grid[y][x]);
	} else if (state == 1) { // only can go to left or down
		ret = max(ret, solve(y + 1, x, 0) + grid[y][x]);
		ret = max(ret, solve(y, x - 1, state) + grid[y][x]);
	} else { // only can go to right or down
		ret = max(ret, solve(y + 1, x, 0) + grid[y][x]);
		ret = max(ret, solve(y, x + 1, state) + grid[y][x]);
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	grid = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &grid[i][j]);
			for (int k = 0; k < 3; k++)
				cache[i][j][k] = -(inf + inf);
		}
//	memset(cache, -1, sizeof(cache));
	printf("%d", solve(0, 0, 0));
	return 0;
}