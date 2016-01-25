
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 5001;
const int MAXK = 1001;

int K, N;
int chopsticks[MAXN];
int cache[MAXN][MAXK];

int penalty(int a, int b) { return abs(chopsticks[a] - chopsticks[b]) * abs(chopsticks[a] - chopsticks[b]); }
int main() {
	scanf("%d%d", &K, &N);
	for (int i = 1; i <= N; i++) scanf("%d", &chopsticks[i]);
	sort(chopsticks + 1, chopsticks + N + 1);
	for (int pos = ?; pos <= N - K; pos++) {
		cache[pos][0] = 0;
		for (int k = 1; k <= K; k++) {
			cache[pos][k] = min(cache[pos - 1][k], cache[pos - 2][k - 1] + penalty(pos - 1, pos));
		}
	}
	printf("%d", cache[N - K][K]);
}