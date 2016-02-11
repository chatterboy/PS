#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 1e9;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

int n;
Point points[10001];
int cache[10001];

int minInstall(int pos) {
	if (pos == 0) return 0;
	int &ret = cache[pos];
	if (ret != -1) return ret;
	ret = inf;
	int x, y = 0;
	for (int k = pos; k >= 1; k--) {
		x = points[pos].x - points[k].x;
		y = max(y, abs(points[k].y));
		ret = min(ret, minInstall(k - 1) + max(2 * y, x));
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &points[i].x, &points[i].y);
	sort(points + 1, points + n + 1, [](const Point &a, const Point &b){
		return a.x < b.x;
	});
	memset(cache, -1, sizeof(cache));
	printf("%d", minInstall(n));
	return 0;
}