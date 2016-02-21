#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
	int cache[5005] = {};
	cache[2] = 1;
	for (int l = 3; l <= 5004; l++)
		for (int i = 0; i <= l; i += 2)
			cache[l] = (cache[l] + ((long long)cache[i] * cache[l - i]) % MOD) % MOD;
	int T;
	scanf("%d", &T);
	while (T--) {
		int L;
		scanf("%d", &L);
		printf("%d\n", cache[L + 2]);
	}
	return 0;
}