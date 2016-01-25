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
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 2e9;
const int MAX = 1001;

struct Point {
	int x, y;
};

int N, W;
Point accidents[MAX];
int cache[MAX][MAX];

int dist(int i, int j) {
	int xi = accidents[i].x;
	int yi = accidents[i].y;
	int xj = accidents[j].x;
	int yj = accidents[j].y;
	if (i == 0) xi = yi = 1;
	else if (i == -1) xi = yi = N;
	return abs(xi - xj) + abs(yi - yj);
}
int solve(int pos, int another) {
	if (pos == W) return 0;
//	printf("%d %d\n", pos, another);
	return min(solve(pos + 1, another) + dist(pos, pos + 1), solve(pos + 1, pos) + dist(another, pos + 1));
}
int main() {
	scanf("%d%d", &N, &W);
	for (int i = 1; i <= W; i++) scanf("%d%d", &accidents[i].y, &accidents[i].x);
	int minv = solve(1, 0) + dist(-1, 1);
	int carno = 2;
	if (minv > solve(1, -1) + dist(0, 1)) {
		minv = carno
	}
	printf("%d", min(solve(1, 0) + dist(-1, 1), solve(1, -1) + dist(0, 1)));
}