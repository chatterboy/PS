// AC
#include <cstdio>

int main()
{
	int r, c, a, b;
	char s[102][102];

	scanf("%d%d", &r, &c);
	for (int i=1; i<=r; ++i) scanf("%s", 1+s[i]);
	scanf("%d%d", &a, &b);

	for (int i=1; i<=r; ++i)
		for (int j=1; j<=c; ++j)
			s[i][j+c] = s[i][c-j+1];

	for (int i=1; i<=r; ++i)
		for (int j=1; j<=2*c; ++j)
			s[i+r][j] = s[r-i+1][j];

	s[a][b] = '#'+'.'-s[a][b];

	for (int i=1; i<=2*r; ++i)
	{
		for (int j=1; j<=2*c; ++j) putchar(s[i][j]);
		putchar('\n');
	}
}