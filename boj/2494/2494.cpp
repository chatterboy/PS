#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10101;

int N;
char src[MAXN], des[MAXN];
int cache[MAXN][10];

int minRotations(int pos, int rotations) {
	if (pos > N) return 0;
	int &ret = cache[pos][rotations];
	if (ret != -1) return ret;
	int s = ((src[pos] - '0') + rotations) % 10;
	int e = des[pos] - '0';
	return ret = min(minRotations(pos + 1, rotations) + ((s - e + 10) % 10),
			   	 minRotations(pos + 1, (rotations + ((e - s + 10) % 10)) % 10) + ((e - s + 10) % 10));
}

void construct(int pos, int rotations) {
	if (pos > N) return;
	int s = ((src[pos] - '0') + rotations) % 10;
	int e = des[pos] - '0';
	if (minRotations(pos + 1, rotations) + ((s - e + 10) % 10) <= minRotations(pos + 1, (rotations + ((e - s + 10) % 10)) % 10) + ((e - s + 10) % 10)) {
		printf("%d %d\n", pos, -1 * ((s - e + 10) % 10));
		construct(pos + 1, rotations);
	} else {
		printf("%d %d\n", pos, ((e - s + 10) % 10));
		construct(pos + 1, rotations + ((e - s + 10) % 10));
	}
}

int main() {
	scanf("%d%s%s", &N, src + 1, des + 1);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", minRotations(1, 0));
	construct(1, 0);
}