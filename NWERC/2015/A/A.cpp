#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define maxn 300003

struct Work {
	int a, s;
} works[maxn];

int n, m;
priority_queue<int> pq;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &works[i].a, &works[i].s);
	sort(works + 1, works + n + 1, [](const Work &w1, const Work &w2){
		return w1.a < w2.a;
	});
	int sol = 0;
	for (int i = 1; i <= n; i++) {
		bool timeOver = true;
		while (!pq.empty()) {
			int t = pq.top();
			pq.pop();
			if (works[i].a >= t && works[i].a < t + m) {
				timeOver = false;
				pq.push(min(t, works[i].a + works[i].s));
				break;
			}
		}
		if (timeOver) {
			sol++;
			pq.push(works[i].a + works[i].s);
		}
	}
	printf("%d", sol);
	return 0;
}