#include <iostream>
#include <algorithm>
using namespace std;

int n, apos, bpos, m, a[21];

int solve(int apos, int bpos, int idx)
{
	if (idx > m) return 0;
	if (a[idx] == apos || a[idx] == bpos)
		return solve(apos, bpos, idx+1);
	else if (a[idx] < apos)
	{
		return solve(a[idx], bpos, idx+1) + apos-a[idx];
	}
	else if (a[idx] > bpos)
	{
		return solve(apos, a[idx], idx+1) + a[idx]-bpos;
	}
	else // (apos, bpos)
	{
		return min(solve(a[idx], bpos, idx+1) + a[idx]-apos,
					solve(apos, a[idx], idx+1) + bpos-a[idx]);
	}
}

int main()
{
	cin >> n >> apos >> bpos >> m;
	for (int i=1; i<=m; ++i) cin >> a[i];

	cout << solve(apos, bpos, 1);
}