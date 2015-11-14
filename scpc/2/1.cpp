#include <cstdio>
typedef long long ll;
int tc, n;
ll a[100000];
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll solve(ll x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	ll ret = 2;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) {
			if (x == i * i) ret++;
			else ret += 2;
		}
	return ret;
}
int main() {
	scanf("%d", &tc);
	for (int tcn = 1; tcn <= tc; tcn++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
		ll ans;
		if (n == 2) {
			ll t = -1;
			for (ll i = 1; i*i <= n; i++)
				if (n % i == 0) {
					if (i*i == n) t++;
					else t += 2;
				}
			ans = t;
		} else {
			ll g = gcd(a[1]-a[0], a[2]-a[1]);
			for (int i = 3; i < n; i++) g = gcd(g, a[i]-a[i-1]);
			ans = solve(g);
			if (ans == 0) { // 이건 영향이 없는 듯 ... 
				bool chk = true;
				for (int i = 1; i < n; i++) chk &= a[i]-a[i-1] == g;
				if (chk) ans++;
			}
		}
		printf("Case #%d\n%lld\n", tcn, ans);
	}
}