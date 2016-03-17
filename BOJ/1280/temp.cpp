#include <bits/stdc++.h>
using namespace std;
/*
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	long long sol = 1;
	for (int i = 1; i < n; i++) {
		long long t = 0;
		for (int j = 0; j < i; j++)
			t = t + abs(arr[i] - arr[j]);
		sol = (sol * t) % 1000000007LL;
	}
	cout << sol;
	return 0;
}
*/

FILE *fout = fopen("output.out", "w");

int main() {
	long long N, L, X0, A, B;
	cin >> N >> L >> X0 >> A >> B;
	cout << N << endl;
	vector<long long> v(N);
	v[0] = X0 % L;
	for (int i = 1; i < N; i++)
		v[i] = (v[i - 1] * A + B) % L;
	fprintf(fout, "%lld\n", N);
	for (int i = 0; i < N; i++)
		fprintf(fout, "%lld\n", v[i]);
	return 0;
}
