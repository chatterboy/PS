// WA

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n;
vector<pair<int,int>> rides;


int solve(int p, int q) {
	if (p < 1 && q < 1) return 0;

	int ret = INF;
	if (p > 0)
		ret = min(ret, solve(p - 1, q) + rides[p].first * 1);
	if (q > 0)
		ret = min(ret, solve(p, q - 1) + rides[q].second * 2);

	if (p > 0) {
		ret = min(ret, solve(p - 1, q) + 3);
		ret = min(ret, solve(p - 7, q) + 18);
		ret = min(ret, solve(p - 30, q) + 45);
	}

	if (p == q && p > 0 && q > 0) {
		ret = min(ret, solve(p - 1, q - 1) + 6);
		ret = min(ret, solve(p - 7, q - 7) + 36);
		ret = min(ret, solve(p - 30, q - 30) + 90);
	}

	return ret;
}

int main() {
	int tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		scanf("%d", &n);
		rides = vector<pair<int,int>>(n + 1);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &rides[i].first, &rides[i].second);
		printf("%d\n", solve(3, 3));
	}
	return 0;
}