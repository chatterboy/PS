// AC
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define mod 1000000

int n, dp[101][101][2];

int solve(int l, int r, int dir)
{
	if (l == 0 && r == 0) return 1;

	int &ret = dp[l][r][dir];
	if (ret != -1) return ret;
	ret = 0;

	if (dir)
	{
		for (int ll=0; ll<l; ++ll)
			ret = (ret + solve(ll, r+l-ll-1, 0)) % mod;
	}
	else
	{
		for (int rr=0; rr<r; ++rr)
			ret = (ret + solve(r+l-rr-1, rr, 1)) % mod;
	}

	return ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));

	cin >> n;

	if (n <= 2)
	{
		cout << n;
		exit(0);
	}

	int ans = 0;

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (i != j)
				ans = (ans + solve(j-(i<j?1:0), n-j-1-(i>j?1:0), i < j)) % mod;

	cout << ans;
}