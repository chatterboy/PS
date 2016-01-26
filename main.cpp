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

#include <cstdio>
#include <algorithm>
using namespace std;

int K, N;
int lengths[5001];
int cache[5001][3001];

int main() {
	scanf("%d%d", &K, &N);
	for (int i = 1; i <= N; i++) scanf("%d", &lengths[i]);
	sort(lengths + 1, lengths + N + 1, [](int a, int b){ return a < b; });
	for (int pos = 3; pos <= N; pos++) {
		for (int k = 3; k <= 3 * K; k++) {
			cache[pos][k] = cache[pos - 1][k];
			cache[pos][k] = min(cache[pos - 1][k],
								cache[pos - 1][k - 1],
								cache[pos - 2][k - 2] + );
		}
	}
	printf("%d", cache[N][3 * K]);
}