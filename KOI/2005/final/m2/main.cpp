#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 500;

int n;
char s[maxn + 1]; // dna
int cache[500][500];

// T[p][q] = dna[p...q]의 부분 서열들 중에서 길이가 최대가 되는 KOI 유전자의 길이
int solve(int p, int q) {
	if (p > q)
		return 0;
	int &ret = cache[p][q];
	if (ret != -1)
		return ret;
	ret = 0;
	if ((s[p] == 'a' && s[q] == 't') || (s[p] == 'g' && s[q] == 'c'))
		ret = max(ret, solve(p + 1, q - 1) + 2);
	else {
		ret = max(ret, solve(p + 1, q));
		ret = max(ret, solve(p, q - 1));
	}
	for (int m = p + 1; m + 1 < q; m++)
		ret = max(ret, solve(p, m) + solve(m + 1, q));
	return ret;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	memset(cache, -1, sizeof(cache));
	printf("%d", solve(0, n - 1));
	return 0;
}