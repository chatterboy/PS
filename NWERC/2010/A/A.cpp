#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int p, n; scanf("%d%d", &p, &n);
		vector<int> a(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum < p) puts("IMPOSSIBLE");
		else {
			vector<int> b(n, p / n);
			int changes = p % n;
			for (int i = 0; i < n; i++)
				if (a[i] < b[i]) {
					changes += b[i] - a[i];
					b[i] = a[i];
				}
			int rich = 0;
			for (int i = 0; i < n; i++)
				if (a[i] - b[i]) rich++;
			while (changes) {
				if (changes >= rich) {
					for (int i = 0; i < n; i++)
						if (a[i] - b[i]) b[i]++;
					changes -= rich;
				} else {
					int maxs = 0;
					for (int i = 0; i < n; i++)
						maxs = max(maxs, a[i] - b[i]);
					for (int i = 0; i < n; i++)
						if (changes && a[i] - b[i] == maxs) b[i]++, changes--;
				}
			}
			for (int i = 0; i < n; i++) printf("%d ", b[i]); puts("");
		}
	}
}