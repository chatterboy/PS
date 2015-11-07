#include <cstdio>
#include <cstring>
int n, m, grid[300][300], d[] = {0, 0, -1, 1};
bool visited[300][300];
void dfs(int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int ii = i + d[k];
		int jj = j + d[(k+2)%4];
		if (grid[ii][jj] > 0 && !visited[ii][jj])
			dfs(ii, jj);
	}
}
int bingsan() {
	memset(visited, false, sizeof(visited));
	bool chk = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (grid[i][j] > 0) {
				chk = true;
				dfs(i, j);
				break;
			}
		if (chk) break;
	}
	if (!chk) return 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] > 0 && !visited[i][j])
				return 2;
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &grid[i][j]);
	int ans = 0;
	while (bingsan() == 1) {
		ans++;
		int melting[300][300] = {{0}};
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] > 0) {
					int t = 0;
					for (int k = 0; k < 4; k++)
						if (grid[i+d[k]][j+d[(k+2)%4]] == 0)
							t++;
					melting[i][j] = t;
				}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] > 0) {
					grid[i][j] -= melting[i][j];
					if (grid[i][j] < 0) grid[i][j] = 0;
				}
	}
	printf("%d", bingsan() ? ans : 0);
}