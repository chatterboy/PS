// AC
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, a[1001];
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &a[i]);
	int dp[1001];
	for (int i=1; i<=n; ++i)
	{
		dp[i] = 1;
		for (int j=1; j<i; ++j)
			if (a[i] > a[j] && dp[i] < dp[j]+1)
				dp[i] = dp[j]+1;
	}
	int ans = dp[1];
	for (int i=2; i<=n; ++i)
		ans = max(ans, dp[i]);
	printf("%d", ans);
}