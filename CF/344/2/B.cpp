// 뒤로부터 하면 시간을 줄 일 수 있다. 

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	vector<vector<int>> grid(N, vector<int>(M, 0));
	while (K--) {
		int q;
		scanf("%d", &q);
		if (q == 1) {
			int r, a;
			scanf("%d%d", &r, &a);
			r--;
			for (int j = 0; j < M; j++)
				grid[r][j] = a;
		} else {
			int c, a;
			scanf("%d%d", &c, &a);
			c--;
			for (int i = 0; i < N; i++)
				grid[i][c] = a;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++)
			printf("%d ", grid[i][j]);
		printf("%d\n", grid[i][M - 1]);
	}
	return 0;
}