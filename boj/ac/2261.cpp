// ac
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
};
int n;
Point p[100000];
vector<int> x, y;
int brute(int l, int r) {
	int ret = 987654321;
	for (int i = l; i <= r; i++)
		for (int j = i+1; j <= r; j++)
			ret = min(ret, (p[x[i]].x - p[x[j]].x) * (p[x[i]].x - p[x[j]].x) +
							(p[x[i]].y - p[x[j]].y) * (p[x[i]].y - p[x[j]].y));
	return ret;
}
int solve(int l, int r, vector<int> &y) {
	if (r - l <= 2) return brute(l, r);
	int mid = (l + r) / 2;
	vector<int> ly, ry;
	for (int i = 0; i < y.size(); i++) {
		if (p[y[i]].y < p[mid].y) ly.push_back(y[i]);
		else ry.push_back(y[i]);
	}
	int d = min(solve(l, mid, ly), solve(mid + 1, r, ry));
	vector<int> yy;
	for (int i = 0; i < y.size(); i++)
		if (abs(p[mid].x - p[y[i]].x) <= d)
			yy.push_back(y[i]);
	for (int i = 0; i < yy.size(); i++)
		for (int j = i+1; j < yy.size() && j-i <= 8; j++)
			d = min(d, (p[yy[i]].x - p[yy[j]].x) * (p[yy[i]].x - p[yy[j]].x) +
						(p[yy[i]].y - p[yy[j]].y) * (p[yy[i]].y - p[yy[j]].y));
	return d;
}
int main() {
	scanf("%d", &n);
	x.resize(n); y.resize(n);
	for (int i = 0; i < n; i++) {
		x[i] = y[i] = i;
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	sort(x.begin(), x.end(), [](int i, int j){ return p[i].x < p[j].x; });
	sort(y.begin(), y.end(), [](int i, int j){ return p[i].y < p[j].y; });
	printf("%d", solve(0, n-1, y));
}