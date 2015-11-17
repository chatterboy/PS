#include <cstdio>
#include <cstring>
int n, no[26][14];
char s[1001];
int main() {
	scanf("%s", s);
	n = strlen(s);
	bool sw = true;
	for (int i = 0; i < n; i+=3) {
		int t = (s[i+1] - '0') * 10 + (s[i+2] - '0');
		if (no[s[i]-'A'][t]++ > 0) sw = false;
	}
	if (!sw) printf("GRESKA");
	else {
		for (int i = 0; i < 4; i++) {
			int t = 0;
			for (int j = 1; j < 14; j++)
				if (no["PKHT"[i]-'A'][j]) t++;
			printf("%d ", 13-t);
		}
	}
}