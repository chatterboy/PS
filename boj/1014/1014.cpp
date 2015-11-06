#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tc, n, m, dp[10][1 << 10];
char grid[10][11];
int ok(int row, int state) {
	int ret = 0;
	for (int i = 0; i < m; i++)
		if (state & (1 << i))
			if (grid[row][i] == '.')
				ret++;
	return ret;
}
bool ook(int row, int state) {
	for (int i = 0; i < m; i++)
		if (state & (1 << i)) {
			if (grid[row][i] == 'x') return false;
			if (i-1 >= 0 && (state & (1 << (i-1))) > 0) return false;
			if (i+1 < m && (state & (1 << (i+1))) > 0) return false;
		}
	return true;
}
bool oook(int row, int state, int _state) {
	if (ook(row, state)) {
		for (int i = 0; i < m; i++)
			if (state & (1 << i)) {
				if (grid[row][i] == 'x') return false;
				if (i-1 >= 0 && (_state & (1 << (i-1))) > 0) return false;
				if (i+1 < m && (_state & (1 << (i+1))) > 0) return false;
			}
		return true;
	}
	return false;
}
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", grid[i]);
		for (int state = 0; state < (1 << m); state++)
			if (ook(0, state))
				dp[0][state] = ok(0, state);
		for (int row = 1; row < n; row++)
			for (int state = 0; state < (1 << m); state++)
				for (int _state = 0; _state < (1 << m); _state++)
					if (oook(row, state, _state))
						dp[row][state] = max(dp[row][state], dp[row-1][_state] + ok(row, state));
		int ans = 0;
		for (int state = 0; state < (1 << m); state++)
			ans = max(ans, dp[n-1][state]);
		printf("%d\n", ans);
		memset(dp, 0, sizeof(dp));
		memset(grid, 0, sizeof(grid));
	}
}
