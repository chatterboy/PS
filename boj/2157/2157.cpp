#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAXN = 300;

int N, M, K;
int yummy[MAXN][MAXN];
int cache[MAXN][MAXN];

int maxYummy(int pos, int cities) {
	if (cities > M) return -INF;
	if (cities == M && pos != N - 1) return -INF;
	bool leaf = true;
	for (int next = 0; next < N; next++) if (yummy[pos][next]) { leaf = false; break; }
//	printf("pos:%d leaf?%d\n", pos+1, leaf?1:0);
	if (leaf) {
		if (pos == N - 1) return 0;
		return -INF;
	}
	int &ret = cache[pos][cities];
	if (ret != -1) return ret;
	ret = -INF;
	for (int next = 0; next < N; next++)
		if (yummy[pos][next]) {
			ret = max(ret, maxYummy(next, cities + 1) + yummy[pos][next]);
		}
	return ret;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		if (a < b) yummy[a][b] = max(yummy[a][b], c);
	}
	memset(cache, -1, sizeof(cache));
	printf("%d", maxYummy(0, 1));
}