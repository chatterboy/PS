#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int cache[11][221][221];

int solve(int pos, int prev, int sum) {
	if (pos > N) {
		return sum == M ? 1 : 0;
	}
	int &ret = cache[pos][prev][sum];
	if (ret != -1) return ret;
	ret = 0;
	for (int num = prev; num + sum <= M; num++)
		ret += solve(pos + 1, num, num + sum);
	return ret;
}


void construct(int pos, int prev, int sum, int k) {
	if (pos > N) {
		return ;
	}
	for (int num = prev; num + sum <= M; num++) {
		if (solve(pos + 1, num, num + sum) == 0 ) continue;
		if (solve(pos + 1, num, num + sum) >= k) {
			printf("%d ", num);
			construct(pos + 1, num, num + sum, k);
			return;
		} else
			k -= solve(pos + 1, num, num + sum);
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	memset(cache, -1, sizeof(cache));
	int res = solve(1, 1, 0);
//	printf("%d\n", res);
	construct(1, 1, 0, K);
	return 0;
}