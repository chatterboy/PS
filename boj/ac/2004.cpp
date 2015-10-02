// AC
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll count(ll a, ll b)
{
	ll ret = 0;
	for (ll bb=b; bb<=a; bb*=b)
		ret += a/bb;
	return ret;
}

int main()
{
	ll n, m;
	cin >> n >> m;

	ll a = count(n, 2), aa = count(n, 5);
	ll b = count(m, 2), bb = count(m, 5);
	ll c = count(n-m, 2), cc = count(n-m, 5);

	ll res1 = a - (b + c), res2 = aa - (bb + cc);

	cout << min(res1, res2);
}