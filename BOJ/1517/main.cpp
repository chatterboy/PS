#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> arr;

ll solve(int s, int e) {
	if (s == e) return 0;
	int m = (s + e) / 2;
	ll lv = solve(s, m);
	ll rv = solve(m + 1, e);
	vector<int> vec;
	ll merges = 0;
	int i = s, j = m + 1;
	while (i <= m && j <= e) {
		if (arr[i] > arr[j]) {
			merges = merges + m - i + 1;
			vec.push_back(arr[j++]);
		} else {
			vec.push_back(arr[i++]);
		}
	}
	if (i <= m) {
		for (int k = i; k <= m; k++)
			vec.push_back(arr[k]);
	}
	if (j <= e) {
		for (int k = j; k <= e; k++)
			vec.push_back(arr[k]);
	}
	for (int i = s; i <= e; i++)
		arr[i] = vec[i - s];
	return lv + rv + merges;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf("%lld", solve(0, n - 1));
	return 0;
}