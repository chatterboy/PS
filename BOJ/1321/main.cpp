#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;
vector<long long> tree;

void init(int i, int s, int e) {
	if (s == e) {
		tree[i] = arr[s];
		return;
	}
	int m = (s + e) / 2;
	init(2 * i, s, m);
	init(2 * i + 1, m + 1, e);
	tree[i] = tree[2 * i] + tree[2 * i + 1];
}

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

long long query(int l, int r, int i, int s, int e) {
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree[i];
	int m = (s + e) / 2;
	return query(l, r, 2 * i, s, m) + query(l, r, 2 * i + 1, m + 1, e);
}

long long psum(int A, int B) {
	long long a = A;
	long long b = B;
	long long ret = b * (b + 1) / 2;
	if (a == 0)
		return ret;
	return ret - a * (a - 1) / 2;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &N, &M);
		arr = vector<int>(N);
		for (int i = 0; i < N; i++)
			arr[i] = i;
		tree = vector<long long>(4 * N);
		init(1, 0, N - 1);
		for (int q = 0; q < M; q++) {
			int Q, A, B;
			scanf("%d%d%d", &Q, &A, &B);
			if (Q == 0) {
				update(A, arr[B], 1, 0, N - 1);
				update(B, arr[A], 1, 0, N - 1);
                swap(arr[A], arr[B]);
			} else {
				long long t = query(A, B, 1, 0, N - 1);
				if (t == psum(A, B))
					puts("YES");
				else
					puts("NO");
			}
		}
	}
	return 0;
}