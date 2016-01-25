#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 2e9;
const int MAXN = 10001;

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
};

int N;
Point points[MAXN];
int inv[MAXN][MAXN];
int cache[MAXN];

int width(int l, int r) {
	return max(2 * inv[l][r], points[r].x - points[l].x);
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d%d", &points[i].x, &points[i].y);
	// sort using x-coordinate
	sort(points+1, points+N+1, [](const Point &a, const Point &b){ return a.x < b.x; });
	// 구간 [i,j]에서 가장 큰 y값 계산
	for (int i = 1; i <= N; i++) {
		inv[i][i] = abs(points[i].y);
		for (int j = i+1; j <= N; j++)
			inv[i][j] = max(inv[i][j-1], abs(points[j].y));
	}	
	cache[1] = width(1, 1);
	for (int pos = 2; pos <= N; pos++) {
		cache[pos] = INF;
		for (int k = 1; k <= pos; k++) {
			cache[pos] = min(cache[pos], cache[pos-k] + width(pos-k+1, pos));
		}
	}
	printf("%d", cache[N]);
}