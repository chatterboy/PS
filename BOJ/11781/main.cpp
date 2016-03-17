#include <bits/stdc++.h>
using namespace std;

const double inf = 9876543219876543.;

struct Edge {
	int there;
	double dist;
	bool isJam;
};

int N, M;
double S, E;
vector<Edge> edges[5001];

double dijkstra() {
	vector<double> times(N + 1, inf);
	priority_queue<pair<double,int>> pq;
	times[1] = .0;
	pq.push(make_pair(.0, 1));
	while (!pq.empty()) {
		double hereTimes = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (times[here] < hereTimes) continue;
		for (int i = 0; i < edges[here].size(); i++) {
			int there = edges[here][i].there;
			double dist = edges[here][i].dist;
			bool isJam = edges[here][i].isJam;
			double delta = times[here];
			if (!isJam || (delta + dist <= S || delta >= E)) {
				double thereTimes = delta + dist;
				if (times[there] > thereTimes) {
					times[there] = thereTimes;
					pq.push(make_pair(-thereTimes, there));
				}
			} else {
				if (delta < S) {
					double len = (S + E) / 2. - delta;
					if (len > dist) { // case 1
						double thereTimes = 2. * (dist + delta) - S;
						if (times[there] > thereTimes) {
							times[there] = thereTimes;
							pq.push(make_pair(-thereTimes, there));
						}
					} else { // case 2
						double thereTimes = dist + delta + (E - S) / 2.;
						if (times[there] > thereTimes) {
							times[there] = thereTimes;
							pq.push(make_pair(-thereTimes, there));
						}
					}
				} else {
					double len = 2. * dist + delta;
					if (len <= E) { // case 3
						double thereTimes = 2 * dist + delta;
						if (times[there] > thereTimes) {
							times[there] = thereTimes;
							pq.push(make_pair(-thereTimes, there));
						}
					} else { // case 4
						double thereTimes = dist + (E + delta) / 2.;
						if (times[there] > thereTimes) {
							times[there] = thereTimes;
							pq.push(make_pair(-thereTimes, there));
						}
					}
				}
			}
		}
	}
	double ret = .0;
	for (int v = 1; v <= N; v++)
		ret = max(ret, times[v]);
	return ret;
}

int main() {
	cin >> N >> M >> S >> E;
	for (int e = 0; e < M; e++) {
		int A, B, t1, t2;
		double L;
		cin >> A >> B >> L >> t1 >> t2;
		edges[A].push_back(Edge{ B, L, (t1 ? true : false) });
		edges[B].push_back(Edge{ A, L, (t2 ? true : false) });
	}
	cout.precision(numeric_limits<double>::digits10 + 1);
	double sol = dijkstra();
	cout << sol;
	return 0;
}