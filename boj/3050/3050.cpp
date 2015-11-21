#include <cstdio>
#include <algorithm>
using namespace std;
int R, C, psum[400][400];
char grid[400][401];
int calc(int r, int c1, int c2) {
	if (c1 < 0) return psum[r][c2];
	return psum[r][c2] - psum[r][c1];
}
int main() {
	scanf("%d%d", &R, &C);
	for (int r = 0; r < R; r++)
		scanf("%s", grid[r]);
	for (int r = 0; r < R; r++) {
		psum[r][0] = grid[r][0] == 'X' ? 1 : 0;
		for (int c = 1; c < C; c++)
			psum[r][c] = psum[r][c-1] + (grid[r][c] == 'X' ? 1 : 0);
	}
	int ans = 0;
	for (int c1 = 0; c1 < C; c1++)
		for (int c2 = c1; c2 < C; c2++) {
			int l = 0;
			for (int r = 0; r < R; r++) {
				if (calc(r, c1 - 1, c2) == 0) {
					l++;
					ans = max(ans, 2 * l + 2 * (c2 - c1 + 1));
				} else {
					l = 0;
				}
			}
		}
	printf("%d", ans == 0 ? 0 : ans - 1);
}