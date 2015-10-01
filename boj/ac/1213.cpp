// AC
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, a[26];
string str;

bool solve(int l, int r, vector<char>& via, vector<char>& vib)
{
	if (l >= r)
	{
		if (l > r) return true;
		int tmp = 0;
		for (int i=0; i<26; ++i)
			tmp += a[i];
		if (tmp == 1)
		{
			for (int i=0; i<26; ++i)
				if (a[i] == 1)
					via.push_back(i+'A');
			return true;
		}
		return false;
	}
	for (int i=0; i<26; ++i)
	{
//		if (a[i] > 0 && a[i]%2 == 0)
		if (a[i] > 1)
		{
			a[i] -= 2;
			via.push_back(i+'A');
			vib.push_back(i+'A');
			if (solve(l+1, r-1, via, vib))
				return true;
			a[i] += 2;
			via.pop_back();
			vib.pop_back();
		}
	}
	return false;
}

int main()
{
	cin >> str;
	n = str.size();
	for (int i=0; i<n; ++i)
		a[str[i]-'A']++;
	int odd = 0;
	for (int i=0; i<26; ++i)
		if (a[i]%2 != 0) odd++;
	if (odd > 1)
	{
		puts("I'm Sorry Hansoo");
		exit(0);
	}
	vector<char> via, vib;
	if (solve(1, n, via, vib))
	{
		for (int i=0; i<via.size(); ++i) putchar(via[i]);
		for (int i=vib.size()-1; i>=0; --i) putchar(vib[i]);
	}
}