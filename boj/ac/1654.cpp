#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int k, n, wire[10000];

bool can(int x)
{
	int no = 0;
	for (int i=0; i<k; ++i)
		no += wire[i] / x;
	return no >= n;
}

int main()
{	
	cin >> k >> n;
	for (int i=0; i<k; ++i)
		cin >> wire[i];

	int lo, hi, ans;

	lo = 1;
	hi = 987654321;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
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

	printf("%d", ans);
}