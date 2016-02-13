#include <cstdio>

// 자연수 x를 이진수로 나타냈을 때, 1의 개수
int f(int x) {
	int ret = 0;
	while (x) {
		if (x & 1) ret++;
		x >>= 1;
	}
	return ret;
}
int main() {
	int N, K; scanf("%d%d", &N, &K);
	int sol = 0;
	while (f(N) > K) N++, sol++;
	printf("%d", sol);
	return 0;
}