#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> a;
vector<int> tree;

int query(int l, int r, int i, int nl, int nr) {
	if (l > nr || r < nl) return 0;
	if (nl >= l && nr <= r) return tree[i];
	int m = (nl + nr) / 2;
	return query(l, r, 2 * i, nl, m) +
		   query(l, r, 2 * i + 1, m + 1, nr);
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
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		a[i] = {t, i};
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		a[i].first = i;
	sort(a.begin(), a.end(), [](const pair<int,int> &l, const pair<int,int> &r){
		return l.second < r.second;
	});
	tree.resize(1 << 22);
	for (int i = 0; i < n; i++) {
		printf("%d\n", query(a[i].first, n - 1, 1, 0, n - 1) + 1);
		update(a[i].first, 1, 1, 0, n - 1);
	}
	return 0;;
}