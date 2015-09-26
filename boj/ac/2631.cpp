#include <iostream>
#include <algorithm>
using namespace std;

int n, a[200], dp[200];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<n; ++i)
	{
		dp[i] = 1;
		for (int j=0; j<i; ++j)
			if (a[i] > a[j])
				dp[i] = max(dp[i], 1+dp[j]);
	}

	int temp = 0;
	for (int i=0; i<n; ++i)
		temp = max(temp, dp[i]);

	cout << n-temp;
}