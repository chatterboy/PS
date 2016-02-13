#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char s[55];
int cache[55][55];

int minOperations(int l, int r) {
	if (l >= r) return 0;
	int &ret = cache[l][r];
	if (ret != -1) return ret;
	if (s[l] == s[r]) ret = minOperations(l + 1, r - 1);
	else {
		ret = min(minOperations(l + 1, r) + 1, min(
				  minOperations(l, r - 1) + 1, minOperations(l + 1, r - 1) + 1));
	}
	return ret;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	memset(cache, -1, sizeof(cache));
	int sol = minOperations(1, n);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			memset(cache, -1, sizeof(cache));
			swap(s[i], s[j]);
			sol = min(sol, minOperations(1, n) + 1);
			swap(s[i], s[j]);
		}
	printf("%d", sol);
	return 0;
}