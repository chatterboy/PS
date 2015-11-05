// ac
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tc, n, w, choragi[2][10000], dp[10000][3];
int goohaja(int p, int moyang) {
	if (p < 0) return 0;
	int &ret = dp[p][moyang];
	if (ret != -1) return ret;
	ret = 20000;
	if (moyang == 0) {
		ret = 1 + min(goohaja(p, 1), goohaja(p, 2));
		if (choragi[0][p] + choragi[1][p] <= w)
			ret = min(ret, 1 + goohaja(p-1, 0));
		if (p >= 1 && choragi[0][p-1] + choragi[0][p] <= w &&
						choragi[1][p-1] + choragi[1][p] <= w)
			ret = min(ret, 2 + goohaja(p-2, 0));
	} else if (moyang == 1) {
		ret = 1 + goohaja(p-1, 0);
		if (p >= 1 && choragi[1][p-1] + choragi[1][p] <= w)
			ret = min(ret, 1 + goohaja(p-1, 2));
	} else {
		ret = 1 + goohaja(p-1, 0);
		if (p >= 1 && choragi[0][p-1] + choragi[0][p] <= w)
			ret = min(ret, 1 + goohaja(p-1, 1));
	}
	return ret;
}
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &w);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++) scanf("%d", &choragi[i][j]);
		memset(dp, -1, sizeof(dp));
		int ans = goohaja(n-1, 0);
		int first = choragi[0][0], second = choragi[1][0];
		if (n > 2) {
			if (choragi[0][n-1] + choragi[0][0] <= w) {
				memset(dp, -1, sizeof(dp));
				choragi[0][0] = w;
				ans = min(ans, goohaja(n-1, 1));
				choragi[0][0] = first;
			}
			if (choragi[1][n-1] + choragi[1][0] <= w) {
				memset(dp, -1, sizeof(dp));
				choragi[1][0] = w;
				ans = min(ans, goohaja(n-1, 2));
				choragi[1][0] = second;
			}
			if (choragi[0][n-1] + choragi[0][0] <= w &&
				choragi[1][n-1] + choragi[1][0] <= w) {
				memset(dp, -1, sizeof(dp));
				choragi[0][0] = choragi[1][0] = w;
				ans = min(ans, goohaja(n-2, 0));
			}
		}
		printf("%d\n", ans);
	}
}