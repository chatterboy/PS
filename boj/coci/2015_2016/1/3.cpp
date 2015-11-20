#include <cstdio>
int n, a[1000001], ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int h;
		scanf("%d", &h);
		if (a[h] == 0) {
			ans++;
			a[h-1]++;
		} else if (a[h] > 0) {
			a[h]--;
			h--;
			a[h]++;
		}
	}
	printf("%d", ans);
}