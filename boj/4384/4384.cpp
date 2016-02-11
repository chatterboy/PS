// WA
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int inf = 1e9;

int n, w[101];
int cache[101][101];

int nearlyEqual(int pos, int inA) {
	if (inA < 0) return inf;
	if (pos == 0) {
		if (inA != 0) return inf;
		return 0;
	}
	int a, b;
	if (inA - 1 >= 0)
		a = nearlyEqual(pos - 1, inA - 1) + w[pos];
	b = nearlyEqual(pos - 1, inA) - w[pos];
	return abs(a) > abs(b) ? b : a;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cache[i][j] = -inf;
	printf("%d", nearlyEqual(n, n / 2));
	return 0;
}