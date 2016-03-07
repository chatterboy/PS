#include <bits/stdc++.h>
using namespace std;

int cache[1001][1001];

int solve(int a, int b) {
	if (a <= 0 || b <= 0) return 0;
	int &ret = cache[a][b];
	if (ret != -1)
		return ret;
	ret = 0;
	if (a >= 2)
		ret = max(ret, 1 + solve(a - 2, b + 1));
	if (b >= 2)
		ret = max(ret, 1 + solve(a + 1, b - 2));
	return ret;
}

int main() {
	int a, b;
	cin >> a >> b;
	memset(cache, -1, sizeof(cache));
	cout << max(solve(a, b), solve(a, b));
	return 0;
}