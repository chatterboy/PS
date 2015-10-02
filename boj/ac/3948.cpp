// AC
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

int n;
ll dp[21][21][2];

ll solve(int l, int r, int dir)
{
	if (l == 0 && r == 0) return 1;

	ll &ret = dp[l][r][dir];
	if (ret != -1) return ret;
	ret = 0;

	if (dir)
	{
		for (int i=0; i<l; ++i)
			ret += solve(i, l+r-i-1, 0);
	}
	else
	{
		for (int i=0; i<r; ++i)
			ret += solve(l+r-i-1, i, 1);
	}

	return ret;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		memset(dp, -1, sizeof(dp));

		cin >> n;

		if (n <= 2)
		{
			cout << n << '\n';
			continue;
		}

		ll ans = 0;

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (i != j)
				{
					int l = j, r = n-j-1;
					if (j > i) l--;
					else if (j < i) r--;
					ans += solve(l, r, i < j);
				}

		cout << ans << '\n';
	}
}