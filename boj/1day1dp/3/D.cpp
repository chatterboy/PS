// T[pos][another] = 
// pos' = pos + 1
// pos'와 pos의 거리, pos'와 another의 거리 
// pos에 있는 경찰차 ?가 pos'와의 거리가 another에서의 거리보다 가까우면
// pos에 있는 경찰차를 그대로 보내는게 더 최적 => T[pos'][another]
// 반대로 pos에 있는 경찰차 ?가 pos'와의 거리보다 another에서의 거리가 더 가까우면
// another로 사용하면 된다. => T[pos'][pos]

// T[pos][another] = pos 사건에 경찰차 1대가 있고 another에 나머지 경찰차가 있을 때
// 					 이동하는 거리의 합의 최소값
// T[pos][another] = min(T[pos'][another] + dist(pos, pos'), T[pos'][pos] + dist(pos', another)) // top-down
// T[pos][another] = min(T[pos-1][another] + dist(pos-1, pos), T[pos-1][pos] + dist(pos, another)) // bottom-up

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXW = 1001;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

int N, W;
Point accidents[MAXW];
int cache[MAXW][MAXW];

int dist(int a, int b) {
	return abs(accidents[a].x - accidents[b].x) + abs(accidents[a].y - accidents[b].y);
}
int minSumDist(int pos, int another) {
	if (pos == W) return 0;
	int &ret = cache[pos][another];
	if (ret != -1) return ret;
	return ret = min(minSumDist(pos + 1, another) + dist(pos, pos + 1),
					 minSumDist(pos + 1, pos) + dist(another, pos + 1));
}
void construct(int pos, int another, int now) {
	if (pos == W) return;
	int minv = minSumDist(pos + 1, another) + dist(pos, pos + 1);
	if (minv > minSumDist(pos + 1, pos) + dist(another, pos + 1)) {
		minv = minSumDist(pos + 1, pos) + dist(another, pos + 1);
		another = pos;
		now = (now == 1 ? 2 : 1);
	}
	printf("%d\n", now);
	construct(pos + 1, another, now);
}
int main() {
	scanf("%d%d", &N, &W);
	accidents[1] = Point(1, 1);
	accidents[2] = Point(N, N);
	for (int i = 3; i <= W + 2; i++)
		scanf("%d%d", &accidents[i].y, &accidents[i].x);
	W += 2;
	memset(cache, -1, sizeof(cache));
	int minv = minSumDist(3, 2) + dist(1, 3);
	int another = 2;
	int now = 1;
	if (minv > minSumDist(3, 1) + dist(2, 3)) {
		minv = minSumDist(3, 1) + dist(2, 3);
		another = 1;
		now = (now == 1 ? 2 : 1);
	}
	printf("%d\n", minv);
	printf("%d\n", now);
	construct(3, another, now);
}