#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
struct Event {
	int x, y1, y2, sg;
	Event(int x, int y1, int y2, int sg) : x(x), y1(y1), y2(y2), sg(sg) {}
	bool operator < (const Event e) const { return x != e.x ? x < e.x : sg > e.sg; }
};
int n;
vector<int> ys, cnt;
vector<Event> events;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ys.push_back(y1); ys.push_back(y2);
		events.push_back(Event(x1, y1, y2, 1));
		events.push_back(Event(x2, y1, y2, -1));
	}
	if (n == 0) { printf("0"); exit(0); }
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());
	sort(events.begin(), events.end());
	cnt.resize(ys.size()-1, 0);
	int ans = 0;
	for (int i = 0; i < events.size(); i++) {
		for (int j = 0; j < ys.size()-1; j++)
			if (ys[j] >= events[i].y1 && ys[j+1] <= events[i].y2)
				cnt[j] += events[i].sg;
		int sero = 0;
		for (int j = 0; j < ys.size()-1; j++)
			if (ys[j] >= events[i].y1 && ys[j+1] <= events[i].y2) {
				if (events[i].sg == 1)
					if (cnt[j] == 1) sero += abs(ys[j+1] - ys[j]);
				if (events[i].sg == -1)
					if (cnt[j] == 0) sero += abs(ys[j+1] - ys[j]);
			}
		ans += sero;
		if (i+1 < events.size()) {
			int t = abs(events[i+1].x - events[i].x);
			for (int j = 0; j < cnt.size(); j++) {
				int garo = 0;
				if (cnt[j] > 0) {
					garo = 2 * t;
					if (j-1 >= 0 && cnt[j-1] > 0) garo -= t;
					if (j+1 < cnt.size() && cnt[j+1] > 0) garo -= t;
				}
				ans += garo;
			}
		}
	}
	printf("%d", ans);
}