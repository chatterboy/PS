#include <cstdio>

int divisors(int x) {
	int ret = 0;
	for (int i = 1; i * i <= x; i++)
		if (x % i == 0) {
			if (i * i != x) ret++;
			ret++;
		}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, lo, hi; scanf("%d%d%d", &n, &lo, &hi);
		int sol = 0;
		for (int x = lo; x <= hi; x++)
			if (divisors(x) == n)
				sol++;
		printf("%d\n", sol);
	}
}