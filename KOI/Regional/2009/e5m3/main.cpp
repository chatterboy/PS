#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10001;

int N;
char src[MAXN], des[MAXN];
int cache[MAXN][10];

int atoi(char c) { return c - '0'; }

int solve(int pos, int rotations) {
//	printf("%d %d\n", pos, rotations);
	if (pos == N) return 0;
	int alpha = atoi(src[pos]) - rotations;
	if (alpha < 0) alpha += 10;
	int delta = atoi(des[pos]) - alpha;
	int delta2 = alpha - atoi(des[pos]);
	int nextRotations = rotations + (delta2 < 0 ? delta2 + 10 : delta2);
	int &ret = cache[pos][rotations];
	if (ret != -1) return ret;
//	printf("delta2:%d\n", delta2 < 0 ? delta2 + 10 : delta2);
	ret = solve(pos + 1, rotations) + (delta2 < 0 ? delta2 + 10 : delta2);
	ret = min(ret, solve(pos + 1, nextRotations % 10) + (delta < 0 ? delta + 10 : delta));
	return ret;
}

void construct(int pos, int rotations) {
	if (pos == N) return;
	int alpha = atoi(src[pos]) - rotations;
	if (alpha < 0) alpha += 10;
	int delta = atoi(des[pos]) - alpha;
	int delta2 = alpha - atoi(des[pos]);
	int nextRotations = rotations + (delta2 < 0 ? delta2 + 10 : delta2);
	int minv = solve(pos + 1, rotations) + (delta2 < 0 ? delta2 + 10 : delta2);
	int dir = -1;
	int mini = (delta2 < 0 ? delta2 + 10 : delta2);
	if (minv > solve(pos + 1, nextRotations % 10) + (delta < 0 ? delta + 10 : delta)) {
		minv = solve(pos + 1, nextRotations % 10) + (delta < 0 ? delta + 10 : delta);
		mini = (delta < 0 ? delta + 10 : delta);
		dir = 1;
	}
	printf("%d %d\n", pos + 1, dir < 0 ? -mini : mini);
	construct(pos + 1, dir > 0 ? nextRotations : rotations);
}

int main() {
	scanf("%d%s%s", &N, src, des);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(0, 0));
	construct(0, 0);
}