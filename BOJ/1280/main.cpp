#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int n;
vector<int> arr;
vector<long long> tree1, tree2;

void update1(int p, int v, int i, int s, int e) {
	if (p < s || p > e) return;
	if (s == e) {
		tree1[i] += v;
		return;
	}
	int m = (s + e) / 2;
	update1(p, v, 2 * i, s, m);
	update1(p, v, 2 * i + 1, m + 1, e);
	tree1[i] = tree1[2 * i] + tree1[2 * i + 1];
}

void update2(int p, int v, int i, int s, int e) {
	if (p < s || p > e) return;
	if (s == e) {
		tree2[i] += v;
		return;
	}
	int m = (s + e) / 2;
	update2(p, v, 2 * i, s, m);
	update2(p, v, 2 * i + 1, m + 1, e);
	tree2[i] = tree2[2 * i] + tree2[2 * i + 1];
}

long long query1(int l, int r, int i, int s, int e) {
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree1[i];
	int m = (s + e) / 2;
	return query1(l, r, 2 * i, s, m) + query1(l, r, 2 * i + 1, m + 1, e);
}

long long query2(int l, int r, int i, int s, int e) {
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree2[i];
	int m = (s + e) / 2;
	return query2(l, r, 2 * i, s, m) + query2(l, r, 2 * i + 1, m + 1, e);
}

FILE *fout = fopen("output.out", "w");

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if (n == 1) {
		printf("0");
		return 0;
	}
	tree1.resize(4 * 200001);
	tree2.resize(4 * 200001);
	update1(arr[0], 1, 1, 0, 200000);
	update2(arr[0], arr[0], 1, 0, 200000);
	long long sol = 1;
	
	for (int i = 1; i < n; i++) {
		long long lv, rv;
		if (arr[i] - 1 >= 0)
			lv = query1(0, arr[i] - 1, 1, 0, 200000) * arr[i] - query2(0, arr[i] - 1, 1, 0, 200000);
		else
			lv = 0;
		if (arr[i] + 1 <= 200000)
			rv = query2(arr[i] + 1, 200000, 1, 0, 200000) - query1(arr[i] + 1, 200000, 1, 0, 200000) * arr[i];
		else
			rv = 0;
		lv %= MOD;
		rv %= MOD;
		sol = (sol * (lv + rv) % MOD) % MOD;
		update1(arr[i], 1, 1, 0, 200000);
		update2(arr[i], arr[i], 1, 0, 200000);
	}
	printf("%lld", sol);
	return 0;
}