#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1010;

int N, W;
int R[MAX], C[MAX];
int cache[MAX][MAX];

int d(int a, int b) { return abs(R[a] - R[b]) + abs(C[a] - C[b]); }

int minDistances(int here, int another) {
	if (here == W) return 0;
	int &ret = cache[here][another];
	if (ret != -1) return ret;
	int next = here + 1;
	return ret = min(minDistances(next, another) + d(here, next),
					 minDistances(next, here) + d(another, next));
}

void construct(int here, int another, int car) {
	if (here == W) return;
	int next = here + 1;
	if (minDistances(next, another) + d(here, next) < minDistances(next, here) + d(another, next)) {
		printf("%d\n", car);
		construct(next, another, car);
	} else {
		printf("%d\n", 3 - car);
		construct(next, here, 3 - car);
	}
}

int main() {
	scanf("%d%d", &N, &W), W++;
	R[0] = C[0] = 1, R[1] = C[1] = N;
	for (int i = 2; i <= W; i++) scanf("%d%d", &R[i], &C[i]);
	memset(cache, -1, sizeof(cache));
	int a = minDistances(2, 1) + d(0, 2), b = minDistances(2, 0) + d(1, 2);
	printf("%d\n", min(a, b));
	if (a < b) {
		puts("1");
		construct(2, 1, 1);
	} else {
		puts("2");
		construct(2, 0, 2);
	}
}