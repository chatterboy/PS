#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846

int N;
vector<pair<long long, int>> D; 
vector<long long> T;

long long query(int l, int r, int i, int nl, int nr) {
	if (nl > r || nr < l) return 0;
	if (nl >= l && nr <= r) return T[i];
	int m = (nl + nr) / 2;
	return max(query(l, r, 2 * i, nl, m),
			   query(l, r, 2 * i + 1, m + 1, nr));
}

void update(int p, long long v, int i, int nl, int nr) {
	if (p < nl || p > nr) return;
	if (nl == nr) {
		T[i] = v;
		return;
	}
	int m = (nl + nr) / 2;
	update(p, v, 2 * i, nl, m);
	update(p, v, 2 * i + 1, m + 1, nr);
	T[i] = max(T[2 * i], T[2 * i + 1]);
}

int main() {
	scanf("%d", &N);
	D.resize(N);
	for (int i = 0; i < N; i++) {
		int r, h;
		scanf("%d%d", &r, &h);
		D[i] = make_pair((long long)r * r * h, i);
	}
	sort(D.begin(), D.end(), [](const pair<long long,int> &a, const pair<long long,int> &b){
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	});
	T.resize(1 << 19);
	for (int i = 0; i < N; i++) {
		long long t = query(0, D[i].second, 1, 0, N - 1) + D[i].first;
		update(D[i].second, t, 1, 0, N - 1);
	}
	printf("%.10f", 1. * PI * T[1]);
	return 0;
}