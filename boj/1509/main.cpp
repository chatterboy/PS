// TLE

#include <bits/stdc++.h>
using namespace std;

int N;
char S[2501];
int cache[2500][2500];
int cache2[2500][2500];

// F[p][q] = 구간 [p...q]는 팰린드롬인가?
int ispal(int p, int q) {
	if (p >= q) return 1;
	int &ret = cache2[p][q];
	if (ret != -1) return ret;
	ret = 0;
	if (S[p] == S[q])
		ret |= ispal(p + 1, q - 1);
	return ret;
}

// T[p][q] = 구간 [p...q]에서 팰린드롬 분할의 수의 최소값
int solve(int p, int q) {
	if (p == q) return 1;
	int &ret = cache[p][q];
	if (ret != -1) return ret;
	ret = 2501;
	if (ispal(p, q) > 0)
		return ret = 1;
	else {
		for (int m = p; m < q; m++)
			ret = min(ret, solve(p, m) + solve(m + 1, q));
	}
	return ret;
}

int main() {
	scanf("%s", &S);
	N = strlen(S);
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	printf("%d", solve(0, N - 1));
	return 0;
}