#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i];
	for (int i = n-3; i >= 0; i-=3)
		ans -= a[i];
	printf("%d", ans);
}