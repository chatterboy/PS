#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;

int n, m;
int a, b, c;
char s1[3001], s2[3001];
vector<vector<int>> cache;

int solve(int i, int j) {
	if (i == 0 && j == 0)
		return 0;
	int &ret = cache[i][j];
	if (ret != -inf) return ret;
	ret = -inf + 99;
	if (i > 0 && j > 0 && s1[i] == s2[j])
		ret = max(ret, solve(i - 1, j - 1) + a);
	else if (i > 0 && j > 0)
		ret = max(ret, solve(i - 1, j - 1) + c);
	if (i > 0)
		ret = max(ret, solve(i - 1, j) + b);
	if (j > 0)
		ret = max(ret, solve(i, j - 1) + b);
	return ret;
}

int main() {
	scanf("%d%d%d", &a, &b, &c);
	scanf("%s%s", s1 + 1, s2 + 1);
	n = strlen(s1 + 1), m = strlen(s2 + 1);
	cache = vector<vector<int>>(n + 1, vector<int>(m + 1, -inf));
	printf("%d", solve(n, m));
	return 0;
}