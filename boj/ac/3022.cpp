// AC
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int n;
	cin >> n;

	map<string, int> m;
	int ans = 0;
	int sum = 0;
	while (n--)
	{
		string a;
		cin >> a;
		int tmp = sum - m[a];
		if (tmp < m[a]) ans++;
		sum++;
		m[a]++;
	}

	cout << ans;
}