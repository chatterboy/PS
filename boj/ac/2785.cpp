// ac
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
int n;
deque<int> chain;
int main() {
	scanf("%d", &n);
	chain.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &chain[i]);
	sort(chain.begin(), chain.end());
	int ans = 0;
	while (chain.size() > 1) {
		chain[0]--;
		ans++;
		chain.pop_back();
		if (chain[0] == 0) chain.pop_front();
	}
	printf("%d", ans);
}