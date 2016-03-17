#include <bits/stdc++.h>
using namespace std;

class ProductOfPrices {
	int n;
	vector<int> arr;
	vector<long long> tree1, tree2;
public:
	void update(vector<long long> &T, int p, int v, int i, int s, int e) {
		if (p < s || p > e) return;
		if (s == e) {
			T[i] += v;
			return;
		}
		int m = (s + e) / 2;
		update(T, p, v, 2 * i, s, m);
		update(T, p, v, 2 * i + 1, m + 1, e);
		T[i] = T[2 * i] + T[2 * i + 1];
	}
	long long query(vector<long long> &T, int l, int r, int i, int s, int e) {
		if (s > r || e < l) return 0;
		if (s >= l && e <= r) return T[i];
		int m = (s + e) / 2;
		return query(T, l, r, 2 * i, s, m) + query(T, l, r, 2 * i + 1, m + 1, e);
	}
	int product(int N, int L, int X0, int A, int B) {
		if (N == 1)
			return 0;
		n = N;
		arr.resize(n);
		arr[0] = X0 % L;
		for (int i = 1; i < n; i++)
			arr[i] = (int)(((long long)arr[i - 1] * A + B) % L);
		tree1.resize(4 * 200001);
		tree2.resize(4 * 200001);
		update(tree1, arr[0], 1, 1, 0, 200000);
		update(tree2, arr[0], 1, 1, 0, 200000);
		long long sol = 1;
		for (int i = 1; i < n; i++) {
			long long lv, rv;
			if (arr[i] - 1 >= 0)
				lv = query(tree1, 0, arr[i] - 1, 1, 0, 200000) * arr[i] - query(tree2, 0, arr[i] - 1, 1, 0, 200000);
			else
				lv = 0;
			if (arr[i] + 1 <= 200000)
				rv = query(tree2, arr[i] + 1, 200000, 1, 0, 200000) - query(tree1, arr[i] + 1, 200000, 1, 0, 200000) * arr[i];
			else
				rv = 0;
			sol = (sol * (lv + rv) % 1000000007) % 1000000007;
			update(tree1, arr[i], 1, 1, 0, 200000);
			update(tree2, arr[i], arr[i], 1, 0, 200000);
		}
		return sol;
	}
}; 