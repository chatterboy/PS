#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int n, m, broken[10];

int len(int x)
{
	stringstream ss; ss << x;
	string str; ss >> str;
	return str.size();
}

bool canGo(int x)
{
	stringstream ss; ss << x;
	string str; ss >> str;
	for (int i=0; i<str.size(); ++i)
		if (broken[str[i]-'0']) return false;
	return true;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i)
	{
		int ti;
		cin >> ti;
		broken[ti] = 1;
	}

	int lclosest, rclosest;

	for (lclosest=n; lclosest>=0; --lclosest)
		if (canGo(lclosest)) break;
	for (rclosest=n; rclosest<=1000000; ++rclosest)
		if (canGo(rclosest)) break;

	int ans = abs(n-100);
	if (lclosest >= 0)
		ans = min(ans, abs(n-lclosest)+len(lclosest));
	if (rclosest <= 1000000)
		ans = min(ans, abs(n-rclosest)+len(rclosest));

	cout << ans;
}
