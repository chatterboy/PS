#include <bits/stdc++.h>
using namespace std;

const long double epsilon = 1;

int main() {
	long long N;
	long double L, W, H;
	cin >> N >> L >> W >> H;
	long double A;
	long double lo = 1.0;
	long double hi = 1e9;		
	while (lo <= hi) {
		long double mid = (lo + hi) / 2.0;
		long long midn = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);
		if (midn >= N) {
			A = mid;
			lo = mid + epsilon;
		} else {
			hi = mid - epsilon;
		}		
	}
	cout << fixed << setprecision(10) << A;
	return 0;
}