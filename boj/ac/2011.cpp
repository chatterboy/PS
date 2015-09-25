#include <cstdio>
#include <cstring>
#define mod 1000000
#define maxn 5005

int n, dp[maxn];
char a[maxn];

int solve(int pos)
{
	if (pos == 0) return 1;
	int &ret = dp[pos];
	if (ret != -1) return ret;
	ret = 0;
	if (pos-1 >= 0 && a[pos] != '0')
		ret = (ret + solve(pos-1)) % mod;
	if (pos-2 >= 0 && ((a[pos-1] == '2' && a[pos] <= '6') || a[pos-1] == '1'))
		ret = (ret + solve(pos-2)) % mod;
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%s", a+1);
	n = strlen(a+1);
	printf("%d", solve(n));
}