#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;
vector<int> T; // 구간에 있는 측정된 온도의 수

void update(int p, int v, int i, int s, int e) {
	if (p < s || p > e) return;
	if (s == e) {
		T[i] += v;
		return;
	}
	int m = (s + e) / 2;
	update(p, v, 2 * i, s, m);
	update(p, v, 2 * i + 1, m + 1, e);
	T[i] = T[2 * i] + T[2 * i + 1];
}

int query(int k, int i, int s, int e) {
	if (s == e)
		return s;
	int m = (s + e) / 2;
	int l = T[2 * i];
	if (k <= l) {
		return query(k, 2 * i, s, m);
	} else {
		return query(k - l, 2 * i + 1, m + 1, e);
	}
}

int main() {
	scanf("%d%d", &N, &K);
	A.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	T.resize(1 << 18);
	for (int i = 0; i < K; i++) {
		update(A[i], 1, 1, 0, 65535);
	}
	long long sol = query((K + 1) / 2, 1, 0, 65535);
	for (int i = K; i < N; i++) {
		update(A[i - K], -1, 1, 0, 65535);
		update(A[i], 1, 1, 0, 65535);
		sol = sol + query((K + 1) / 2, 1, 0, 65535);
	}
	printf("%lld", sol);
	return 0;
}