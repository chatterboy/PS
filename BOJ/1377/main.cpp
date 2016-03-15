#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int N;
vector<pii> arr;
vector<int> tree;

void update(int p, int v, int i, int s, int e) {
	if (p < s || p > e) return;
	if (s == e) {
		tree[i] = v;
		return;
	}
	int m = (s + e) / 2;
	update(p, v, 2 * i, s, m);
	update(p, v, 2 * i + 1, m + 1, e);
	tree[i] = tree[2 * i] + tree[2 * i + 1];
}

int query(int l, int r, int i, int s, int e) {
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree[i];
	int m = (s + e) / 2;
	return query(l, r, 2 * i, s, m) +
		   query(l, r, 2 * i + 1, m + 1, e);
}

int main() {
	scanf("%d", &N);
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		arr[i].first = i;
		scanf("%d", &arr[i].second);
	}
	sort(arr.begin(), arr.end(), [](const pii &a, const pii &b){
		if (a.second != b.second) return a.second > b.second;
		return a.first > b.first;
	});
	tree.resize(4 * N);
	int sol = 0;
	for (int i = 0; i < N; i++) {
		int t = query(0, arr[i].first, 1, 0, N - 1);
		update(arr[i].first, 1, 1, 0, N - 1);
		sol = max(sol, t);
	}
	printf("%d", sol + 1);
	return 0;
}