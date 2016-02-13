// 비숍을 놓을 수 있는 곳 1, 놓을 수 없는 곳 0

#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int board[10][10];

void set(int r, int c, int v) {
	board[r][c] += v;
	for (int t = 1; r + t < N && c + t < N; t++) board[r + t][c + t] += v;
	for (int t = 1; r + t < N && c - t >= 0; t++) board[r + t][c - t] += v;
	for (int t = 1; r - t >= 0 && c + t < N; t++) board[r - t][c + t] += v;
	for (int t = 1; r - t >= 0 && c - t >= 0; t++) board[r - t][c - t] += v;
}
int maxBishops(int k) {
	if (k == 2 * N - 1) return 0;
	int ret = maxBishops(k + 1);
	if (k < N) { // 점점 커지는...
		for (int i = 0; i <= k; i++) {
			int r = k - i, c = i;
			if (board[r][c] == 0) {
				set(r, c, 1);
				ret = max(ret, maxBishops(k + 1) + 1);
				set(r, c, -1);
			}
		}
	} else { // 점점 작아지는...
		for (int i = N - 1; i >= k - N + 1; i--) {
			int r = i, c = k - i;
			if (board[r][c] == 0) {
				set(r, c, 1);
				ret = max(ret, maxBishops(k + 1) + 1);
				set(r, c, -1);
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		int t; scanf("%d", &t);
		board[i][j] = t == 1 ? 0 : 1;
	}
	printf("%d", maxBishops(0));
	return 0;
}