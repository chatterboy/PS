#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, s, a[40];
vector<int> b1, b2, c1, c2;
void solve(int pos, int sum, vector<int>& b, vector<int>& c)
{
	if (pos == b.size())
	{
		c.push_back(sum);
		return;
	}
	solve(pos+1, sum, b, c);
	solve(pos+1, sum+b[pos], b, c);
}
int main()
{
	cin >> n >> s;
	for (int i=0; i<n; ++i) cin >> a[i];

	for (int i=0; i<n/2; ++i) b1.push_back(a[i]);
	for (int i=n/2; i<n; ++i) b2.push_back(a[i]);

	solve(0, 0, b1, c1);
	solve(0, 0, b2, c2);

	sort(c1.begin(), c1.end());
	sort(c2.begin(), c2.end());

	ll ans = 0;

	for (int i=0; i<c1.size(); ++i)
	{
		int ti = s-c1[i];
		ll first = lower_bound(c2.begin(), c2.end(), ti) - c2.begin();
		ll last = upper_bound(c2.begin(), c2.end(), ti) - c2.begin();

		if (first < c2.size())
		{
			if (c2[first] == ti)
			{
				while (c2[last-1] != ti) last--;
				ans += last-first;
			}
		}
	}

	if (s == 0) ans--;

	printf("%lld", ans);
}