#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 100001
#define maxm 31

int tc, n, m, c, data[maxm], op[maxn], dp[maxn][maxm];

int solve(int pos, int area1)
{
	if (pos > n) return 0;
	int &ret = dp[pos][area1];
	if (ret != -1) return ret;
	if (op[pos] == area1)
	{
		return ret = solve(pos+1, area1);
	}	
	else
	{
		return ret = min(solve(pos+1, area1) + data[op[pos]], solve(pos+1, op[pos]) + c);
	}
}

int main() 
{
	scanf("%d", &tc);
	while (tc--)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d%d%d", &n, &m, &c);
		for (int i=1; i<=m; ++i) scanf("%d", &data[i]);
		for (int i=1; i<=n; ++i) scanf("%d", &op[i]);
		printf("%d\n", solve(1, 0));
	}
}