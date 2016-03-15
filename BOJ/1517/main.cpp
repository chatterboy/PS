#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int k, n, wire[10000];

bool can(long long x)
{
	long long no = 0;
	for (int i=0; i<k; ++i)
		no += wire[i] / x;
	return no >= n;
}

int main()
{	
	cin >> k >> n;
	for (int i=0; i<k; ++i)
		cin >> wire[i];

	long long lo, hi, ans;

	lo = 1;
	hi = 987654321987654321;
	while (lo <= hi)
	{
		long long mid = (lo + hi) / 2;
		if (can(mid))
		{
			if (!can(mid+1)) { ans = mid; break; }
			lo = mid+1;
		}
		else
		{
			hi = mid-1;
		}
	}

	printf("%lld", ans);
}