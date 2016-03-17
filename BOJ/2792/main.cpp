#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	vector<int> arr(M);
	for (int i = 0; i < M; i++) scanf("%d", &arr[i]);
	int sol;
	int lo = 1, hi = 1000000000;
	while (lo <= hi) {
		int mid = (long long)((long long)lo + hi) / 2;
		int count = 0;
		for (int i = 0; i < M; i++)
			count += arr[i] / mid + (arr[i] % mid != 0 ? 1 : 0);
		if (count <= N) {
			sol = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	printf("%d", sol);
	return 0;
}