// ac
#include <iostream>
using namespace std;
long long l, r;
bool chk[1000001];
void f(long long x) { chk[x - l] = true; }
int main() {
	cin >> l >> r;
	for (long long i = 2; i*i <= r; i++) {
		long long q = l / (i*i);
		for (long long j = (i*i)*q; j <= r; j+=i*i)
			if (j >= l && j <= r)
				f(j);
	}
	int ans = 0;
	for (long long i = l; i <= r; i++)
		ans += chk[i - l] ? 0 : 1;
	cout << ans;
}