#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int move(char now, char next) {
	int r = 0;
	char ch = now;
	while (ch != next) {
		r++;
		ch++;
		if (ch > 'Z') ch = 'A';
	}
	int l = 0;
	ch = now;
	while (ch != next) {
		l++;
		ch--;
		if (ch < 'A') ch = 'Z';
	}
	return min(l, r);
}
int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		char name[1001] = {}; scanf("%s", name);
		int n = strlen(name);
		char now = 'A';
		int sol = n - 1;
		int pos = 0;
		while (pos != n - 1) {
			int temp = move(now, name[pos]);
			printf("%c %d\n", now, temp);
			sol += temp;
			now = name[pos++];
		}
		printf("%d\n\n", sol);
	}
}