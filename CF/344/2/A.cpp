#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<long long> A(N), B(N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &A[i]);
	for (int i = 0; i < N; i++)
		scanf("%lld", &B[i]);
	vector<long long> psumA(N), psumB(N);
	psumA[0] = A[0];
	psumB[0] = B[0];
	for (int i = 1; i < N; i++) {
		psumA[i] = psumA[i - 1] | A[i];
		psumB[i] = psumB[i - 1] | B[i];
	}
	long long sol = 0;
	for (int l = 0; l < N; l++)
		for (int r = l; r < N; r++) {
			long long ta = psumA[l];
			if (l > 0)
				ta &= psumA[l - 1];
			long long tb = psumB[r];
			if (r > 0)
				tb &= psumB[r - 1];
			sol = max(sol, ta + tb);
		}
	printf("%lld", sol);
	return 0;
}