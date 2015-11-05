// ac
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
struct Event {
	int x, y1, y2, nero;
	Event(int x, int y1, int y2, int nero) :
		x(x), y1(y1), y2(y2), nero(nero) {}
	bool operator < (const Event e) const { return x < e.x; }
};
int tc, n;
vector<int> ys, cnt;
vector<Event> events;
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			ys.push_back(y1);
			ys.push_back(y2);
			events.push_back(Event(x1, y1, y2, 1));
			events.push_back(Event(x2, y1, y2, -1));
		}
		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());
		sort(events.begin(), events.end());
		cnt.resize(ys.size()-1, 0);
		long long ans = 0;
		for (int i = 0; i < events.size()-1; i++) {
			for (int j = 0; j < ys.size()-1; j++)
				if (ys[j] >= events[i].y1 && ys[j+1] <= events[i].y2)
					cnt[j] += events[i].nero;
			int len = 0;
			for (int j = 0; j < cnt.size(); j++)
				if (cnt[j] > 0)
					len += abs(ys[j+1] - ys[j]);
			ans += (long long)abs(events[i+1].x - events[i].x) * len;
		}
		printf("%lld\n", ans);
		ys.clear();
		cnt.clear();
		events.clear();
	}
}