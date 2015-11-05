// ac
#include <cstdio>
int n, x[1000000], k[21];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	for (int i = 0; i < n; i++) {
		int t = x[i];
		for (int j = 0; j < 21; j++) {
			k[j] += (t & 1);
			t >>= 1;
		}
	}
	long long ans = 0;
	for (int i = 0, pw = 1; i < 21; i++, pw*=2)
		ans += (long long)k[i] * (n - k[i]) * pw;
	printf("%lld", ans);
}