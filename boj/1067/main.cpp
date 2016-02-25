#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &X[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &Y[i]);
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	int sol = 0;
	for (int i = 0; i < N; i++)
		sol += X[i] * Y[i];
	printf("%d", sol);
	return 0;
}