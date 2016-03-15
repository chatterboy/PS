#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d, k, c;
	scanf("%d%d%d%d", &n, &d, &k, &c);
	vector<int> sushi(n + k - 1);
	for (int i = 0; i < n; i++)
		scanf("%d", &sushi[i]);
	for (int i = n; i < n + k - 1; i++)
		sushi[i] = sushi[i - n];
	vector<int> type(d + 1, 0);
	for (int i = 0; i < k; i++)
		type[sushi[i]]++;
	int sol = 0;
	for (int i = 1; i <= d; i++)
		if (type[i] > 0)
			sol++;
	if (type[c] == 0) sol++;
	int prevv = sol;
	for (int prev = 0, next = k; next < n + k - 1; prev++, next++) {
		int t = prevv;
		if (--type[sushi[prev]] == 0) t--;
		if (++type[sushi[next]] == 1) t++;
		if (type[c] == 0) t++;
		sol = max(sol, t);
		prevv = type[c] == 0 ? t - 1 : t;
	}
	printf("%d", sol);
	return 0;
}