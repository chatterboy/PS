#include <cstdio>
#include <cstring>
int X, n;
char s[1001];
int main() {
	preprocess();
	scanf("%d%s", &X, s);
	n = strlen(s);
	X = X % period[n];
	// solve...
}