// bfs는 안됨 

#include <cstdio>
#include <queue>
using namespace std;

const int INF = 2e9;
const int d[] = { 0, 0, -1, 1 };

struct State {
	int r, c;
	int times;
	int dir;
	State(int r = 0, int c = 0, int times = 0, int dir = -1) : r(r), c(c), times(times), dir(dir) {}
};

int N, M;
char grid[51][52];
queue<State> q;
int cache[51][51][4];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%s", grid[i] + 1);
		for (int j = 1; j <= M; j++) {
			if (grid[i][j] == 'S') q.push(State(i, j, 0));
			for (int k = 0; k < 4; k++) cache[i][j][k] = INF;
		}
	}
	while (!q.empty()) {
		State now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int r = now.r + d[i], c = now.c + d[(i + 2) % 4], times = now.times + 1, dir = i;
			if (dir == now.dir) continue;
			if (r >= 1 && r <= N && c >= 1 && c <= M) {
				if (cache[r][c][dir] > times) {
					cache[r][c][dir] = times;
					q.push(State(r, c, times, dir));
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) printf("%d\n", cache[1][2][i]);
	for (int i = 0; i < 4; i++) printf("%d\n", cache[1][3][i]);
}