// ac
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
struct Point {
	int x, y;
};
int tc, n;
Point point[20];
vector<bool> picked;
long long solve(int p, int m) {
	if (p == n) {
		if (m == 0) {
			long long x = 0, y = 0;
			for (int i = 0; i < n; i++) {
				if (picked[i]) { x += point[i].x; y += point[i].y; }
				else { x -= point[i].x; y -= point[i].y; }
			}
			return x*x + y*y;
		}
		return 987564321987654321;
	}
	long long ret = 987654321987654321;
	for (int i = 0; i < 2; i++) {
		if (m-i >= 0) {
			picked[p] = i ? true : false;
			ret = min(ret, solve(p+1, m-i));
			picked[p] = false;
		}
	}
	return ret;
}
int main() {
	cin >> tc;
	cout << fixed << setprecision(6);
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> point[i].x >> point[i].y;
		picked = vector<bool>(n, false);
		cout << sqrt((double)solve(0, n/2)) << '\n';
	}
}