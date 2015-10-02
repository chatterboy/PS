// AC
#include <cstdio>
#include <cstring>

int main()
{
	char a[100+1] = {0};
	scanf("%s", a);

	int n = strlen(a);

	int cr, cc;

	for (int r=1; r<=n; ++r)
		for (int c=1; c<=n; ++c)
			if (r <= c && r*c == n)
				if (cr < r)
				{
					cr = r;
					cc = c;
				}

	char bd[100][100+1] = {{0}};
	char *pch = a;

	for (int c=0; c<cc; ++c)
		for (int r=0; r<cr; ++r)
			bd[r][c] = *pch++;

	for (int r=0; r<cr; ++r)
		for (int c=0; c<cc; ++c) putchar(bd[r][c]);
}