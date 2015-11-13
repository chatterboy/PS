#include <cstdio>
int tc, n, m;
char grid[400][401];
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		for (int r = 0; r < n; r++) scanf("%s", grid[r]);
		int ans = 0;
		for (int r = 0; r < n; r++)
			for (int c = 0; c < m; c++)
				if (grid[r][c] == 'o') {
					if ((grid[r][c-1] == '>' && c-1 >= 0) && (grid[r][c+1] == '<' && c+1 < m)) ans++;
					else if ((grid[r-1][c] == 'v' && r-1 >= 0) && (grid[r+1][c] == '^' && r+1 < n)) ans++;
				}
		printf("%d\n", ans);
	}
}