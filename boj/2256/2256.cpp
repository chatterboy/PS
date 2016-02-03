#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e12;

int K, N;
vector<long long> sticks;
long long cache[5001][1001];

long long minPenalites(int pos, int k) {
	if (pos < 3 * k) return INF;
	if (pos == 1) {
		return 0;
	}
	long long &ret = cache[pos][k];
	if (ret != -1) return ret;
	ret = INF;
	if (pos - 1 >= 1) ret = min(ret, minPenalites(pos - 1, k));
	if (pos - 2 >= 1 && k - 1 >= 0) ret = min(ret, minPenalites(pos - 2, k - 1) + (sticks[pos - 1] - sticks[pos])
																				* (sticks[pos - 1] - sticks[pos]));
	return ret;
}

int main() {
	scanf("%d%d", &K, &N);
	sticks.resize(N + 1);
	sticks[0] = INF;
	for (int i = 1; i <= N; i++) scanf("%lld", &sticks[i]);
	sort(sticks.rbegin(), sticks.rend());
	memset(cache, -1, sizeof(cache));
	printf("%lld", minPenalites(N, K));
}