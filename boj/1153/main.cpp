#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;
vector<vector<int>> cache;

int solve(int l, int r) {
	if (l >= r) return 1;
	int &ret = cache[l][r];
	if (ret != -1) return ret;
	ret = 0;
	if (A[l] == A[r])
		ret |= solve(l + 1, r - 1);
	return ret;
}

int main() {
	int N;
	scanf("%d", &N);
	A = vector<int>(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	cache = vector<vector<int>>(N, vector<int>(N, -1));
	scanf("%d", &M);
	while (M--) {
		int S, E;
		scanf("%d%d", &S, &E);
		S--, E--;
		printf("%d\n", solve(S, E));
	}
	return 0;
}