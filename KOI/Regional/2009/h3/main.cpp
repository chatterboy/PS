#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 2e9;
const int MAXN = 21;

int N;
int fields[MAXN][MAXN];
int totalHarvest;
int cache[MAXN][MAXN][40001];

int alpha(int pos, int e) {
	int ret = 0;
	for (int i = 1; i <= e; i++) ret += fields[pos][i];
	return ret;
}

int divideFairly(int pos, int width, int white) {
	if (pos > N) {
		return abs(totalHarvest - 2 * white);
	}
	int &ret = cache[pos][width][white];
	if (ret != -1) return ret;
	ret = INF;
	for (int nextWidth = width; nextWidth >= 0; nextWidth--)
		ret = min(ret, divideFairly(pos + 1, nextWidth, white + alpha(pos, width)));
	return ret;
}

void construct(int pos, int width, int white) {
	if (pos > N) return;
	int minv = INF;
	int minWidth = -1;
	for (int nextWidth = width; nextWidth >= 0; nextWidth--)
		if (minv > divideFairly(pos + 1, nextWidth, white + alpha(pos, width))) {
			minv = divideFairly(pos + 1, nextWidth, white + alpha(pos, width));
			minWidth = nextWidth;
		}
	printf("%d ", N - width);
	construct(pos + 1, minWidth, white);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &fields[i][j]);
			totalHarvest += fields[i][j];
		}
	memset(cache, -1, sizeof(cache));
	int minv = INF;
	int minWidth = -1;
	for (int width = 0; width <= N; width++) {
		if (minv > divideFairly(1, width, alpha(1, width))) {
			minv = divideFairly(1, width, alpha(1, width));
			minWidth = width;
		}
	}
	printf("%d\n", minv);
	construct(1, minWidth, alpha(1, minWidth));
}