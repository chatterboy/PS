// AC
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, mat[16][16], p, dp[1<<16];

int solve(int vst)
{
	int howMany = 0;
	for (int i=0, tmp=vst; i<n; ++i, tmp>>=1)
		if (tmp & 1) howMany++;
	if (howMany >= p) return 0;

	int &ret = dp[vst];
	if (ret != -1) return ret;
	ret = 987654321;

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
		{
			if (((1 << i) & vst) && !((1 << j) & vst))
			{
				ret = min(ret, solve(vst | (1 << j)) + mat[i][j]);
			}
		}

	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) scanf("%d", &mat[i][j]);
	char buf[17];
	scanf("%s%d", buf, &p);

	int vst = 0;
	for (char *ch=buf; *ch; ++ch)
	{
		int tmp = ch - buf;
		if (*ch == 'Y') vst |= (1 << tmp);
	}

	for (int i=0; i<(1<<16); ++i) dp[i] = -1;
    
	int ans = solve(vst);
	printf("%d", ans==987654321?-1:ans);
}