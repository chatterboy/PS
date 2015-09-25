#include <cstdio>
int n, m;
char gallery[1010][1010];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) scanf("%s", gallery[i]+1);

	int ans = 0;

	int first, second;

	first = second = 0;
	for(int i=1; i<n; ++i)
	{
		for (int j=1; j<=m; ++j)
		{
			if (gallery[i][j] == 'X' && gallery[i+1][j] == '.')
			{
				first++;
				
				ans += second / 2;
				second = 0;
			}
			else if (gallery[i][j] == '.' && gallery[i+1][j] == 'X')
			{
				second++;

				ans += first / 2;
				first = 0;
			}
			else
			{
				ans += first/2 + second/2;
				first = second = 0;
			}
		}
	}

	// i == n
	second = 0;
	for (int j=1; j<=m; ++j)
	{
		if (gallery[n][j] == '.')
		{
			second++;
		}
		else
		{
			ans += second / 2;
			second = 0;
		}
	}

	first = second = 0;
	for (int j=1; j<m; ++j)
	{
		for (int i=1; i<=n; ++i)
		{
			if (gallery[i][j] == 'X' && gallery[i][j+1] == '.')
			{
				first++;

				ans += second / 2;
				second = 0;
			}
			else if (gallery[i][j] == '.' && gallery[i][j+1] == 'X')
			{
				second++;

				ans += first / 2;
				first = 0;
			}
			else
			{
				ans += first/2 + second/2;
				first = second = 0;
			}
		}
	}

	// j == m
	second = 0;
	for (int i=1; i<=n; ++i)
	{
		if (gallery[i][m] == '.')
		{
			second++;
		}
		else
		{
			ans += second / 2;
			second = 0;
		}
	}


	printf("%d", ans);
}