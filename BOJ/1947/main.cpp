#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

const lld MOD = 1e9;

int main() {
	int N;
	cin >> N;
	vector<lld> cache(3);
	cache[1] = 0;
	cache[2] = 1;
	for (int i = 3; i <= N; i++)
		cache[i % 3] = ((i - 1) * (cache[(i - 1) % 3] + cache[(i - 2) % 3])) % MOD;
	cout << cache[N % 3];
	return 0;
}