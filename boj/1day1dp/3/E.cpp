// T[N] = N일 째 되는 날 살아있는 짚신벌레의 수

// 태어난 후 a일부터 한 마리씩 만들어낸다.
// b일 째부터 만들지 않는다.
// d일 째 되면 죽는다.

// T[N] = (b-a)*T[N-a]-T[N-d]

#include <cstdio>

const int MOD = 1000;

int a, b, d, N;
int cache[1000001];

int main() {
	scanf("%d%d%d%d", &a, &b, &d, &N);
	cache[0] = 1;
	for (int i = N-d+1; i <= N; i++)
		cache[i] = (b-a)*cache[N-a] - cache[N-d];
	printf("%d", cache[N]);
}