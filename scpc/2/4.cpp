#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Inv {
	int l, r;
};
int tc, n, a[100001], ans[100001], T[400004];
Inv inv[100000];
bool cmp(const Inv& a, const Inv& b) {
	if (a.l < b.l) return true;
	if (a.l > b.l) return false;
	return a.r > b.r;
}
int query(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (tl == l && tr == r) return T[v];
	int tm = (tl + tr) / 2;
	return max(query(2*v, tl, tm, l, min(tm, r)), query(2*v+1, tm+1, tr, max(tm+1, l), r));
}
void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		T[v] = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if (tm >= pos) update(2*v, tl, tm, pos, val);
	else update(2*v+1, tm+1, tr, pos, val);
	T[v] = max(T[2*v], T[2*v + 1]);
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &tc);
	for (int tcn = 1; tcn <= tc; tcn++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			inv[i].l = l; inv[i].r = r;
		}
		sort(inv, inv + n, cmp);
		reverse(inv, inv + n);
		for (int i = 1; i <= n; i++) a[i] = inv[i-1].r;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			ans[a[i]] = query(1, 1, n, 1, a[i]-1) + 1;
			update(1, 1, n, a[i], ans[a[i]]);
			res = max(res, ans[a[i]]);
		}
		printf("Case #%d\n", tcn);
		printf("%d\n", res);
	}
}
/*
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Inv {
	int l, r;
};
int tc, n;
int dp[100000];
Inv inv[100000];
bool cmp(const Inv& a, const Inv& b) {
	if (a.l < b.l) return true;
	if (a.l > b.l) return false;
	return a.r > b.r;
}
int solve2() {
	int ret = 0;
	for (int i = 0; i < n; i++) dp[i] = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (inv[i].r >= inv[j].r && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		ret = max(ret, dp[i]);
	}
	return ret;
}
int dy[100002];
int binarySearch(int lb, int ub, int key) {
	int mid = (lb + ub) / 2;
	if (ub - lb <= 0) return lb;
	if (dy[mid] > key)
		return binarySearch(lb, mid-1, key);
	else if (dy[mid] < key)
		return binarySearch(mid+1, ub, key);
	else
		return mid;
}
int solve() {
	int size = 0;
	for (int i = 0; i < n; i++) dy[i] = -1;
	dy[size++] = inv[0].r;
	for (int i = 1; i < n; i++) {
		if (inv[i].r >= dy[size-1])
			dy[size++] = inv[i].r;
		else {
			int p = binarySearch(0, size-1, inv[i].r);
			dy[p] = inv[i].r;
		}
	}
	return size;
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &tc);
	for (int tcn = 1; tcn <= tc; tcn++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			inv[i].l = l; inv[i].r = r;
		}
		sort(inv, inv + n, cmp);
		reverse(inv, inv + n);
		printf("Case #%d\n", tcn);
		printf("%d\n", solve());
	}
}
*/