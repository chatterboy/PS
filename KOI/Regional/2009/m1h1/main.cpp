#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc = 3;
	while (tc--) {
		char s[9] = {}; scanf("%s", s);
		int sol = 1;
		int len = 1;
		for (int i = 1; i < 8; i++) {
			if (s[i] == s[i - 1]) len++;
			else {
				sol = max(sol, len);
				len = 1;
			}
		}
		sol = max(sol, len);
		printf("%d\n", sol);
	}
}