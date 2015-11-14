#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define inf 987654321
int tc, n, m, k, h[101][101], dp[101][101][203];
bool water[101][101];
int solve(int y, int x, int _k) {
	if (y == n && x == m) {
		if (_k >= k) return 0;
		return inf;
	}
	int &ret = dp[y][x][_k];
	if (ret != -1) return ret;
	ret = inf;
	if (y+1 <= n) {
		if (water[y+1][x])
			ret = min(ret, abs(h[y][x] - h[y+1][x]) + solve(y+1, x, _k+1));
		else
			ret = min(ret, abs(h[y][x] - h[y+1][x]) + solve(y+1, x, _k));
	}
	if (x+1 <= m) {
		if (water[y][x+1])
			ret = min(ret, abs(h[y][x] - h[y][x+1]) + solve(y, x+1, _k+1));
		else
			ret = min(ret, abs(h[y][x] - h[y][x+1]) + solve(y, x+1, _k));
	}
	return ret;
}
int main() {
	scanf("%d", &tc);
	for (int tcn = 1; tcn <= tc; tcn++) {
		scanf("%d%d%d", &m, &n, &k);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++) {
				int t;
				scanf("%d", &t);
				if (t < 0) { water[i][j] = true; t *= -1; }
				h[i][j] = t;				
			}
		memset(dp, -1, sizeof(dp));
		printf("Case #%d\n%d\n", tcn, solve(0, 0, 0));
		memset(water, false, sizeof(water));
	}
}