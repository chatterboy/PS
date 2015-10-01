// AC
#include <cstdio>
#include <deque>
#include <utility>
using namespace std;
typedef long long ll;

int n;
ll a[500000];
deque<pair<ll, ll>> dq;

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%lld", &a[i]);

	ll ans = 0;

	dq.push_back(make_pair(a[n-1], 1));
	for (int i=n-2; i>=0; --i)
	{
		if (a[i] > dq.back().first)
		{
			while (!dq.empty() && a[i] > dq.back().first)
			{
				ans += dq.back().second;
				dq.pop_back();
			}
			if (!dq.empty() && a[i] == dq.back().first)
			{
				ans += dq.back().second;
				dq.back().second++;
				if (dq.size() > 1) ans++;
			}
			else
			{
				if (!dq.empty()) ans++;
				dq.push_back(make_pair(a[i], 1));
			}
		}
		else if (a[i] < dq.back().first)
		{
			ans++;
			dq.push_back(make_pair(a[i], 1));
		}
		else
		{
			ans += dq.back().second;
			dq.back().second++;
			if (dq.size() > 1) ans++;
		}
	}

	printf("%lld", ans);
}