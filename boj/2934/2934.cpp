#include <cstdio>

#define MAXN 100010

int N;
int tree[4 * MAXN];
int lazy[4 * MAXN];

void updateLazy(int l, int r, int i) {
	tree[i] += (r - l + 1) * lazy[i];
	if (l != r) {
		lazy[2 * i] += lazy[i];
		lazy[2 * i + 1] += lazy[i];
	}
	lazy[i] = 0;
}

int update(int l, int r, int i, int nl, int nr, int val) {
	updateLazy(nl, nr, i);
	if (l > nr || r < nl) return tree[i];
	if (l <= nl && nr <= r) {
		lazy[i] += val;
		return tree[i] + val * (nr - nl + 1);
	}
	return tree[i] = update(l, r, 2 * i, nl, (nl + nr) / 2, val) +
					 update(l, r, 2 * i + 1, (nl + nr) / 2 + 1, nr, val);
}

int query(int l, int r, int i, int nl, int nr) {
	updateLazy(nl, nr, i);
	if (l > nr || r < nl) return 0;
	if (l <= nl && nr <= r) return tree[i];
	return query(l, r, 2 * i, nl, (nl + nr) / 2) + query(l, r, 2 * i + 1, (nl + nr) / 2 + 1, nr);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int L, R; scanf("%d%d", &L, &R);
		int a = query(L, L, 1, 1, 100000), b = query(R, R, 1, 1, 100000);
		printf("%d\n", a + b);
		update(L, L, 1, 1, 100000, -a), update(R, R, 1, 1, 100000, -b);
		if (L + 1 < R) update(L + 1, R - 1, 1, 1, 100000, 1);
	}
	return 0;
}