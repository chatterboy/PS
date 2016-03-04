#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> perm;
vector<int> tree;

int query(int l, int r, int i, int nl, int nr) {
	if (nl > r || nr < l) return 0;
	if (nl >= l && nr <= r) return tree[i];
	int m = (nl + nr) / 2;
	return query(l, r, 2 * i, nl, m) + query(l, r, 2 * i + 1, m + 1, nr);
}

void update(int id, int v, int i, int nl, int nr) {
	if (id < nl || id > nr) return;
	if (nl == nr) {
		tree[i] = v;
		return;
	}
	int m = (nl + nr) / 2;
	update(id, v, 2 * i, nl, m);
	update(id, v, 2 * i + 1, m + 1, nr);
	tree[i] = tree[2 * i] + tree[2 * i + 1];
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			a[--t] = i;
		}
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			b[--t] = i;
		}
		perm = vector<int>(n);
		for (int i = 0; i < n; i++)
			perm[a[i]] = b[i];
		tree = vector<int>(4 * n, 0);
		long long sol = 0;
		for (int i = 0; i < n; i++) {
			sol = sol + query(perm[i], n - 1, 1, 0, n - 1);
			update(perm[i], 1, 1, 0, n - 1);
		}
		printf("%lld\n", sol);
	}
	return 0;
}