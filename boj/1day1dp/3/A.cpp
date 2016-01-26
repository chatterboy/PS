// pos번 젓가락은
// 1) 사용하지 않을 수 있다
// 2) 짧은 젓가락 두 개 중 하나로 사용할 수 있다
// 3) 긴 젓가락으로 사용할 수 있다

// 2)에서 짧은 것 두 개로 사용할 때는 인접한 것 끼리 사용하는 것이 최적이다.

// T[pos] = pos까지 고려했을 때 벌점의 총 합의 최솟값

// T[pos][k] = pos까지 고려하고 k

// T[pos][short][long] = pos까지 고려하고 짧은 젓가락 쌍을 short개, 긴 젓가락 long개를
//						 뽑았을 때, 벌점의 총 합의 최소값

// T[5000][3000]

// T[pos][k] = pos까지 고려했고 젓가락 k개를 뽑았을 때, 벌점의 총 합의 최소값
// T[pos][k] = T[pos-2][k-2] + cost(pos-1,pos)
// T[pos][k] = T[pos-1][k]
// T[pos][k] = T[pos-1][k-1]

// T[pos][k] = pos전 까지 고려했고 k개를 뽑았을 때, 벌점의 총 합의 최소값

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 2e9;

int K, N;
int lengths[5001];
int cache[5001][3001];

int solve(int pos, int k, int depth) {
	for (int i = 0; i < depth; i++) printf(" ");
	printf("pos:%d k:%d\n", pos, k);
	if (pos > N) {
//		printf("pos:%d k:%d\n", pos, k);
		if (k != 3 * K) return INF;
//		printf("pos:%d k:%d\n", pos, k);
		return 0;
	}
	int &ret = cache[pos][k];
	if (ret != -1) return ret;
	ret = solve(pos + 1, k, depth + 3);
	if (k + 1 <= 3 * K)
		ret = min(ret, solve(pos + 1, k + 1, depth + 3));
	if (pos + 1 <= N && k + 2 <= 3 * K)
		ret = min(ret, solve(pos + 2, k + 2, depth + 3) +
			abs(lengths[pos] - lengths[pos + 1]) * abs(lengths[pos] - lengths[pos + 1]));
	return ret;
}
int main() {
	scanf("%d%d", &K, &N);
	for (int i = 1; i <= N; i++) scanf("%d", &lengths[i]);
	sort(lengths + 1, lengths + N + 1, [](int a, int b){ return a < b; });
	memset(cache, -1, sizeof(cache));
	printf("%d", solve(1, 0, 0));
}