// ac
#include <cstdio>
#include <algorithm>
using namespace std;
int n, mat[400][400];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	int ans = -987654321;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int beauty = 0, maxBeauty = 0;
			int x1, y1, x2, y2, x3, y3, x4, y4;
			x1 = x2 = x3 = x4 = j; y1 = y2 = y3 = y4 = i;
			while (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n &&
					x2 >= 0 && x2 < n && y2 >= 0 && y2 < n &&
					x3 >= 0 && x3 < n && y3 >= 0 && y3 < n &&
					x4 >= 0 && x4 < n && y4 >= 0 && y4 < n) {
				beauty += (mat[y1][x1] + mat[y3][x3]) - (mat[y2][x2] + mat[y4][x4]);
				maxBeauty = max(maxBeauty, beauty);
				x1++; y1++;
				x2++; y2--;
				x3--; y3--;
				x4--; y4++;
			}
			ans = max(ans, maxBeauty);
		}
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n-1; j++) {
			int x1, y1, x2, y2, x3, y3, x4, y4;
			x1 = j, y1 = i;
			x2 = j+1, y2 = i;
			x3 = j, y3 = i+1;
			x4 = j+1, y4 = i+1;
			int beauty = 0;
			int maxBeauty = (mat[y1][x1] + mat[y4][x4]) - (mat[y2][x2] + mat[y3][x3]);
			while (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n &&
					x2 >= 0 && x2 < n && y2 >= 0 && y2 < n &&
					x3 >= 0 && x3 < n && y3 >= 0 && y3 < n &&
					x4 >= 0 && x4 < n && y4 >= 0 && y4 < n) {
				beauty += (mat[y1][x1] + mat[y4][x4]) - (mat[y2][x2] + mat[y3][x3]);
				maxBeauty = max(maxBeauty, beauty);
				x1--; y1--;
				x2++; y2--;
				x3--; y3++;
				x4++; y4++;
			}
			ans = max(ans, maxBeauty);
		}
	printf("%d", ans);
}