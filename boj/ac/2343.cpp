#include <cstdio>
#define maxn 100010
int n, m, a[maxn];
bool can(int x)
{
	int sum, no;

	sum = 0;
	no = 1;
	for (int i=1; i<=n; ++i)
	{
		if (sum+a[i] <= x)
		{
			sum += a[i];
		}
		else
		{
			sum = a[i];
			no++;
		}
	}

	return no <= m;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) scanf("%d", &a[i]);

	int lo, hi;

	lo = 0, hi = 1000000000;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (can(mid))
		{
			if (!can(mid-1))
			{
				printf("%d", mid);
				break;
			}
			hi = mid-1;
		}
		else
		{
			lo = mid+1;
		}
	}
}