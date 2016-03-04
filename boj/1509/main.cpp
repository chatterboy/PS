#include <bits/stdc++.h>
using namespace std;

bool ispal(int l, int r, string &s) {
	while (l < r) {
		if (s[l++] != s[r--])
			return false;
	}
	return true;
}

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> cache(n);
	for (int i = 0; i < n; i++) {
		if (ispal(0, i, s)) {
			cache[i] = 1;
			continue;
		}
		cache[i] = i + 1;
		for (int j = 1; j <= i; j++)
			if (ispal(i - j + 1, i, s))
				cache[i] = min(cache[i], cache[i - j] + 1);
	}
	cout << cache[n - 1];
	return 0;
}