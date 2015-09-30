// AC
#include <cstdio>
#include <cstdlib>
int main()
{
	
	char bd[5][5];
	for (int i=0; i<4; ++i) scanf("%s", bd[i]);

	int ans = 0;
	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			if (bd[i][j] != '.')
			{
				int k = bd[i][j]-'A';
				ans += abs(k/4-i) + abs(k%4-j);
			}
	printf("%d", ans);
}