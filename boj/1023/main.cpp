// 길이가 N인 괄호ㄴㄴ문자열 중에서 사전순으로 K번째인 문자열을 출력해라.

// 1. 길이가 N인 괄호 ㄴㄴ문자열의 개수
// 2. 실제로 문자열을 추적

// 아이디어 1. => 올바른 괄호 문자열을 이용하자.
// 길이가 N일 때 나타날 수 있는 문자열의 수는 2^N 개이다. => F
// 길이가 N일 때 올바른 문자열의 수는 catalan number임을 알고 있으니까 => G
// 길이가 N인 괄호ㄴㄴ문자열의 수 => F' = F - G

// 아이디어 2. => 직접 구하고 싶다..
// 적어도 하나의 괄호가 unvalid하면 그 문자열은 괄호ㄴㄴ문자열이다.

#include <bits/stdc++.h>
using namespace std;

int N;
long long K;
long long cache[51][51];

long long solve(int pos, int lefts) {
	if (lefts < 0) {
		long long pw = 1;
		for (int i = 0; i < N - pos; i++)
			pw <<= 1;
		return pw;
	}
	if (pos == N) {
		return lefts > 0 ? 1 : 0;
	}
	long long &ret = cache[pos][lefts];
	if (ret != -1) return ret;
	return ret = solve(pos + 1, lefts - 1) + solve(pos + 1, lefts + 1);
}

void construct(int pos, int lefts, long long k) {
//	printf("pos:%d lefts:%d k:%lld -> %lld, %lld\n", pos, lefts, k, solve(pos + 1, lefts + 1), solve(pos + 1, lefts - 1));
	if (lefts < 0) {
		long long pw = 1;
		for (int i = 1; i < N - pos; i++)
			pw <<= 1;
		for (int i = 0; i < N - pos; i++) {
			if (pw >= k)
				putchar('(');
			else {
				putchar(')');
				k -= pw;
			}
			pw >>= 1;
		}
		return;
	}
	if (pos == N) return;
	if (solve(pos + 1, lefts + 1) + solve(pos + 1, lefts - 1) < k) {
		printf("-1");
		return;
	}
	if (solve(pos + 1, lefts + 1) >= k) {
		putchar('(');
		construct(pos + 1, lefts + 1, k);
	} else {
		putchar(')');
		construct(pos + 1, lefts - 1, k - solve(pos + 1, lefts + 1));
	}
}

int main() {
	scanf("%d%lld", &N, &K);
	memset(cache, -1, sizeof(cache));
	long long res = solve(0, 0);
//	printf("%lld\n", res);
	construct(0, 0, K + 1);
	/*
	for (long long k = 0; k < K; k++) {
		construct(0, 0, k + 1);
		puts("");
	}
	*/
	return 0;
}