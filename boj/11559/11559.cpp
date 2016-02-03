#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int d[] = { 0, 0, -1, 1 };

int n, m;
char puyo[13][8];
bool visited[13][8];

int howMany(int r, int c, int flag) {
	visited[r][c] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int rr = r + d[i], cc = c + d[(i + 2) % 4];
		if (rr >= 1 && rr <= n && cc >= 1 && cc <= m) {
			if (!visited[rr][cc] && puyo[r][c] == puyo[rr][cc])
				ret += howMany(rr, cc, flag);
		}
	}
	if (flag) puyo[r][c] = '.';
	return ret;
}

void gravity() {
	for (int c = 1; c <= m; c++)
		for (int r = n; r >= 1; r--)
			if (puyo[r][c] != '.') {
				for (int rr = r; rr + 1 <= n && puyo[rr + 1][c] == '.'; rr++)
					swap(puyo[rr][c], puyo[rr + 1][c]);
			}
}

bool bomb() {
	bool puyopuyo = false;
	memset(visited, false, sizeof(visited));
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			if (puyo[i][j] != '.' && !visited[i][j]) {
				int puyos = howMany(i, j, 0);
				if (puyos >= 4) {
					puyopuyo = true;
					memset(visited, false, sizeof(visited));
					howMany(i, j, 1); // remove
				}
			}
	gravity();
	return puyopuyo;
}

int main() {
	n = 12, m = 6;
	for (int i = 1; i <= n; i++) scanf("%s", puyo[i] + 1);
	int sol = 0;
	gravity();
	while (bomb()) {
		sol++;
	}
	printf("%d", sol);
}