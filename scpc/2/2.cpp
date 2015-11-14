#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int tc, a, b, c, n, k;
int main() {
	scanf("%d", &tc);
	for (int tcn = 1; tcn <= tc; tcn++) {
		scanf("%d%d%d", &a, &b, &c);
		vector<char> ans;
		for (int i = 0; i < c; i++) {
			scanf("%d%d", &n, &k);
			if (a > b) {
				if (n <= a) ans.push_back('b');
				else ans.push_back('a');
			} else {
				// a == b
				int p = n % (a * (1 + k));
				if (p >= 1 && p <= a) ans.push_back('b');
				else ans.push_back('a');
			}
		}
		printf("Case #%d\n", tcn);
		for (int i = 0; i < (int)ans.size(); i++) putchar(ans[i]);
		putchar('\n');
	}
}