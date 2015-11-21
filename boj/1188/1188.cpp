#include <cstdio>
#include <cmath>
int main() {
	double n, m;
	scanf("%lf %lf", &n, &m);
	int ans = (ceil(m / n) - 1) * n;
	printf("%d", (int)ans);
}