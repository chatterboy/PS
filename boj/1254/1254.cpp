#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int N;
char s[1010];
int cache[1010][1010][2];

int shortestLength(int i, int j, int flag) {
	if (i >= j) return i == j ? 1 : 0;
	int &ret = cache[i][j][flag];
	if (ret != -1) return ret;
	ret = INF;
	if (!flag) ret = min(ret, shortestLength(i + 1, j, flag) + 2);
	if (s[i] == s[j]) ret = min(ret, shortestLength(i + 1, j - 1, 1) + 2);
	return ret;
}

int main() {
	scanf("%s", s + 1);
	N = strlen(s + 1);
	memset(cache, -1, sizeof(cache));
	printf("%d", shortestLength(1, N, 0));
}