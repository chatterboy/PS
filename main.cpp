#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> Ball;

int n;
vector<Ball> balls;
int sizeTable[2001];
int psum[2001];
vector<pair<int,int>> sizeTableInColor[200001];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int color, size; scanf("%d%d", &color, &size);
		balls.push_back(make_pair(color, size));
		sizeTable[size] += size;
		sizeTableInColor[color].push_back(make_pair(size, 0));
	}
	psum[1] = sizeTable[1];
	for (int size = 2; size <= 2000; size++) psum[size] = psum[size - 1] + sizeTable[size];
	for (int color = 1; color <= 200000; color++) if (!sizeTableInColor[color].empty()) {
		sort(sizeTableInColor[color].begin(), sizeTableInColor[color].end());
		sizeTableInColor[color][0].second = sizeTableInColor[color][0].first;
		for (int i = 1; i < sizeTableInColor[color].size(); i++)
			sizeTableInColor[color][i] = sizeTableInColor[color][i - 1] + sizeTableInColor[color][i].first;
	}
	for (int i = 0; i < n; i++) {
		int color = balls[i].first, size = balls[i].second;
		int sol = (size == 1 ? 0 : psum[size - 1]);
		auto p = lower_bound(sizeTableInColor[color].begin(), sizeTableInColor[color].end(), size) - sizeTableInColor[color].begin();
		if (p > 0) sol -= sizeTableInColor[color][p - 1].second;
		printf("%d\n", sol);
	}
}