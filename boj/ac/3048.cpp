// AC
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	reverse(a.begin(), a.end());
	vector<int> group(n, 0);
	string b;
	cin >> b;
	a += b;
	for (int i=0; i<m; ++i) group.push_back(1);

	int t;
	cin >> t;

	while (t--)
	{
		for (int i=1; i<a.size();)
		{
			if (group[i] == 1 && group[i-1] == 0)
			{
				swap(group[i], group[i-1]);
				swap(a[i], a[i-1]);
				i += 2;
			} else i++;
		}
	}

	cout << a;
}