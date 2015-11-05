// ac
#include <cstdio>
#include <algorithm>
using namespace std;
int r, c;
char grid[750][751];
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) scanf("%s", grid[i]);
	int ans = 0, maxsz = min(r, c)/2 + 1;
	for (int sz = 1; sz <= maxsz; sz++) {
		bool found = false;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				if ((i-sz+1 >= 0) && (i+sz-1 < r) && (j-sz+1 >= 0) && (j+sz-1 < c)) {
					int x1 = j-sz+1, x2 = j+sz-1;
					bool found2 = true;
					for (int t = 0; x1+t <= x2-t; t++) {
						if (grid[i-t][x1+t] == '0' || grid[i-t][x2-t] == '0') { found2 = false; break; }
						if (grid[i+t][x1+t] == '0' || grid[i+t][x2-t] == '0') { found2 = false; break; }
					}
					if (found2) { found = true; break; }
				}
			if (found) break;
		}
		if (found) ans = sz;
	}
	printf("%d", ans);
}