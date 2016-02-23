#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int inf = 1e9;

int N, K;
vector<pair<int,int>> P;
int cache[500][500];

int d(int p, int q) {
	return abs(P[p].x - P[q].x) + abs(P[p].y - P[q].y);
}

// T[p][k] = [0...p]까지 고려하고, k번 건너뛰어서 달리는 최소거리
int solve(int p, int k) {
	if (p == 0) {
		if (k > 0) return inf;
		return 0;
	}
	int &ret = cache[p][k];
	if (ret != -1) return ret;0
	ret = solve(p - 1, k) + d(p - 1, p);
	for (int i = 1; i <= k && p - 1 - i >= 0; i++)
		ret = min(ret, solve(p - 1 - i, k - i) + d(p - 1 - i, p));
	return ret;
}

int main() {
	scanf("%d%d", &N, &K);
	P.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &P[i].x, &P[i].y);
	memset(cache, -1, sizeof(cache));
	printf("%d", solve(N - 1, K));
	return 0;
}