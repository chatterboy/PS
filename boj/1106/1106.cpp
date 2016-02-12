#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int C, N;
int a[21], b[21];
int cache[21][2001];

int minCost(int pos, int customers) {
	if (pos > N) {
		if (customers < C) return INF;
		return 0;
	}
	if (customers > 2000) return INF;

	int &ret = cache[pos][customers];
	if (ret != -1) return ret;

	return ret = min(minCost(pos + 1, customers),
					 minCost(pos, customers + b[pos]) + a[pos]);
}

int main() {
	scanf("%d%d", &C, &N);
	for (int i = 1; i <= N; i++) scanf("%d%d", &a[i], &b[i]);

	memset(cache, -1, sizeof(cache));
	printf("%d", minCost(1, 0));

	return 0;
}