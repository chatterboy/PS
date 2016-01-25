// 벌점을 계산할 때 C는 상관없다.
// A와 B의 차가 작게 뽑는 것이 최적이다. (가정)

// 3N == K 이면 그리디하게 뽑는 것이 최적이다. (위의 경우를 이용해서)
// 3N > K 이면 dp
// 어쨋건 인접한 2개를 뽑는게 최적이다. 여기서 뽑고 저 멀리서 뽑는건 절대아님

// T[pos][k] = 젓가락 pos 위치에서 k명 더 줘야할 때 , 벌점의 총합의 최소값
// T[pos][k] = min(T[pos-1][k], T[pos-2][k-1] + penalty(pos-1, pos))

// 사람 수 K, 젓가락 수 N

// pos <= N-K

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const long long INF = 2e18;
const int MAXN = 5001;
const int MAXK = 1001;

int K, N;
int chopsticks[MAXN];
long long cache[MAXN][MAXK];

int penalty(int a, int b) { return abs(chopsticks[a] - chopsticks[b]) * abs(chopsticks[a] - chopsticks[b]); }
long long solve(int pos, int k) {
	if (pos > N) {
		if (k > 0) return INF;
		return 0;
	}
	long long &ret = cache[pos][k];
	if (ret != -1) return ret;
	ret = solve(pos+1, k);
	if (k > 0 && pos+1 <= N) ret = min(ret, solve(pos+2, k-1) + penalty(pos, pos+1));
	return ret;
}
int main() {
	scanf("%d%d", &K, &N);
	for (int i = 1; i <= N; i++) scanf("%d", &chopsticks[i]);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
			cache[i][j] = -1;
	sort(chopsticks + 1, chopsticks + N + 1);
	for (int i = 1; i <= N; i++) printf("%d ", chopsticks[i]); puts("");
	printf("%lld", solve(1, K));
}