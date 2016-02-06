#include <cstdio>

const int MAXN = 100001;

int N, L;
int t[MAXN], d[MAXN];

int main() {
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; i++) scanf("%d%d", &t[i], &d[i]);
	printf("%d", longestZigzags());
}