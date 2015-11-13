#include <cstdio>
int N, M, U, L, R, D;
char bd[10][11], bd2[20][21];
int main() {
	scanf("%d%d%d%d%d%d", &N, &M, &U, &L, &R, &D);
	for (int r = 0; r < N; r++) scanf("%s", bd[r]);
	for (int r = 0; r < N+U+D; r++)
		for (int c = 0; c < M+L+R; c++) {
			if ((r + c) & 1) bd2[r][c] = '.';
			else bd2[r][c] = '#';
		}
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			bd2[U+r][L+c] = bd[r][c];
	for (int r = 0; r < N+U+D; r++) puts(bd2[r]);
}