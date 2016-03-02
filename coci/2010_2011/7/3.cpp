#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, P;
	scanf("%d%d", &N, &P);
	vector<stack<int>> st(6);
	int sol = 0;
	for (int i = 0; i < N; i++) {
		int cord, fret;
		scanf("%d%d", &cord, &fret);
		cord--;
		while (!st[cord].empty() && st[cord].top() > fret)
			sol++, st[cord].pop();
		if (st[cord].empty() || st[cord].top() < fret)
			sol++, st[cord].push(fret);
	}
	printf("%d", sol);
	return 0;
}