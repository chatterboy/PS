#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int move(char src, char des) {
	int lc = 0, rc = 0;
	char l = src;
	while (l != des) {
		l++, lc++;
		if (l > 'Z') l = 'A';
	}
	char r = src;
	while (r != des) {
		r--, rc++;
		if (r < 'A') r = 'Z';
	}
	return min(lc, rc);
}
int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		char s[1001] = {}; scanf("%s", s);
		int n = strlen(s);
		int mismatches = 0;
		for (int i = 0; i < n; i++) if (s[i] != 'A') mismatches++;
		char sa[1001] = {};
		char sb[1001] = {};
		for (int i = 0; i < n; i++) sa[i] = sb[i] = s[i];
		int bk = mismatches;
		int pos = 0;
		int r = 0, l = 0;
		while (mismatches > 0) {
			if (sa[pos] != 'A') {
				r += move('A', sa[pos]), mismatches--;
				sa[pos] = 'A';
			}
			pos++;
			r++;
			if (pos == n) pos = 0;
		}
		mismatches = bk;
		pos = 0;
		while (mismatches > 0) {
			if (sb[pos] != 'A') {
				l += move('A', sb[pos]), mismatches--;
				sb[pos] = 'A';
			}
			pos--;
			l++;
			if (pos < 0) pos = n - 1;
		}
		printf("%d\n", min(r, l));
	}
}