// sol = N - LIS

// (a,b)쌍을 저장 => Q
// a기준 정렬
// (id,b) 쌍 저장 => P
// b 기준 정렬
// ㄱㄱ

// (a,b)쌍 저장 => Q
// a 기준 정렬
// (i,b)쌍 저장 => P
// b 기준 정렬 

// query => 구간 내 최대값을 가지는 원소의 인덱스


#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> T;
vector<int> A; // LIS 값을 저장
vector<int> B; // 

int query(int l, int r, int i, int nl, int nr) {
	if (nl > r || nr < l)
		return -1;
	if (nl >= l && nr <= r) {
		return T[i];
	}
	int m = (nl + nr) / 2;
	int ql = query(l, r, 2 * i, nl, m);
	int qr = query(l, r, 2 * i + 1, m + 1, nr);
	int lv, rv;
	if (ql == -1) lv = 0;
	else lv = A[ql];
	if (qr == -1) rv = 0;
	else rv = A[qr];
	return lv > rv ? ql : qr;
}

void update(int p, int v, int i, int l, int r) {
	if (p < l || p > r)
		return;
	if (l == r) {
		A[p] = v;
		T[i] = p;
		return;
	}
	int m = (l + r) / 2;
	update(p, v, 2 * i, l, m);
	update(p, v, 2 * i + 1, m + 1, r);
	int lv = A[T[2 * i]];
	int rv = A[T[2 * i + 1]];
	T[i] = lv > rv ? T[2 * i] : T[2 * i + 1];
}

int main() {
	int N;
	scanf("%d", &N);
	vector<pii> Q(N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Q[i] = make_pair(a, b);
	}
	sort(Q.begin(), Q.end());
	vector<pii> P(N);
	for (int i = 0; i < N; i++) {
		P[i] = make_pair(i, Q[i].second);
	}
	sort(P.begin(), P.end(), [](const pii &l, const pii &r){
		return l.second < r.second;
	});
	T.resize(1 << 19);
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; i++) {
		int p = query(0, P[i].first, 1, 0, N - 1);
		printf("%d\n", p);
		update(P[i].first, A[p] + 1, 1, 0, N - 1);
	}
	printf("%d\n", A[T[1]]);
	return 0;
}