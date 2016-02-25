#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> grid;

// i번째 행에서 가질 수 있는 최적값
int row_opt(int i) {
	vector<int> col_cache(M);
	col_cache[0] = grid[i][0];
    if (M > 1)
	    col_cache[1] = max(col_cache[0], grid[i][1]);
	for (int j = 2; j < M; j++) {
		col_cache[j] = col_cache[j - 1];
		col_cache[j] = max(col_cache[j], col_cache[j - 2] + grid[i][j]);
	}
	return col_cache[M - 1];
}

int main() {
	while (scanf("%d%d", &N, &M), N | M) {
		grid = vector<vector<int>>(N, vector<int>(M));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &grid[i][j]);
		vector<int> row_cache(N);
		row_cache[0] = row_opt(0);
        if (N > 1)
		    row_cache[1] = max(row_cache[0], row_opt(1));
		for (int i = 2; i < N; i++) {
			row_cache[i] = row_cache[i - 1];
			row_cache[i] = max(row_cache[i], row_cache[i - 2] + row_opt(i));
		}
		printf("%d\n", row_cache[N - 1]);
	}
	return 0;
}