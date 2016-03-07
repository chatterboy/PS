#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> P;
vector<int> tree;

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

int query(int l, int r, int i, int nl, int nr) {
	if (nl > r || nr < l) return 0;
	if (nl >= l && nr <= r) return tree[i];
	int m = (nl + nr) / 2;
	return query(l, r, 2 * i, nl, m) + query(l, r, 2 * i + 1, m + 1, nr);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		P = vector<int>(n + 1);
		tree = vector<int>(888888);
		for (int i = 1; i <= n; i++) {
			P[i] = i;
			update(i, 1, 1, 1, n + m);
		}
		for (int i = 0; i < m; i++) {
			int t;
			scanf("%d", &t);
			int k = P[t];
			printf("%d ", query(n - k + 1, n + m, 1, 1, n + m));
			update(n - k + 1, 0, 1, 1, n + m);
			update(n + i + 1, 1, 1, 1, n + m);
			P[i] = n + i + 1;
		}
		puts("");
	}
	return 0;
}