// ac
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Range {
	int l, r;
	Range(int l, int r) : l(l), r(r) {}
};
int n, a[100001];
bool chk[100001];
vector<Range> ranges;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int l = -1, r;
	int maxs = 0;
	for (int i = 0; i <= n;) {
		if (a[i] < 0) {
			l = i;
			while (a[i] < 0) i++;
			r = i;
			for (int j = 3*l-2*r; j < l; j++)
				if (j >= 0)
					chk[j] = 1;
			if (r - l > maxs) {
				maxs = r - l;
				ranges.clear();
				ranges.push_back(Range(l, r));
			} else if (r - l == maxs)
				ranges.push_back(Range(l, r));
			l = -1;
		} else i++;
	}
	maxs = 0;
	for (auto e : ranges) {
		int l = e.l, r = e.r;
		int t = 0;
		for (int i = 4*l-3*r; i < 3*l-2*r; i++)
			if (i >= 0 && !chk[i])
				t++;
		maxs = max(maxs, t);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans += chk[i] ? 1 : 0;
	printf("%d", ans + maxs);
}