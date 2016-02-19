// 화재가 발생한 n개의 지역에 m개의 소방서에서 소방차를 보낼 때 도착하는데
// 걸리는 시간의 합의 최소값

// 노드 0을 추가하고 m개의 노드와 걸리는 시간이 0인 간선을 추가한다.

// dijkstra(0)를 고고 

#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int INF = 1e9;
const int MAXV = 1001;

int V;
vector<pair<int,int>> edges[MAXV];

vector<int> dijkstra(int src) {
	vector<int> dist(V, INF);
	priority_queue<pair<int,int>> pq;
	dist[src] = 0;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int vc = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (dist[v] < vc) continue;
		for (int i = 0; i < edges[v].size(); i++) {
			int w = edges[v][i].first;
			int wc = dist[v] + edges[v][i].second;
			if (dist[w] > wc) {
				dist[w] = wc;
				pq.push(make_pair(-wc, w));
			}
		}
	}
	return dist;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int E, n, m;
		scanf("%d%d%d%d", &V, &E, &n, &m);
		V++;
		for (int e = 0; e < E; e++) {
			int v, w, t;
			scanf("%d%d%d", &v, &w, &t);
			edges[v].push_back(make_pair(w, t));
			edges[w].push_back(make_pair(v, t));
		}
		vector<int> fire(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &fire[i]);
		vector<int> water(m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &water[i]);
			edges[0].push_back(make_pair(water[i], 0));
		}
		vector<int> dist = dijkstra(0);
		int sol = 0;
		for (int i = 0; i < n; i++)
			sol += dist[fire[i]];
		printf("%d\n", sol);
		for (int v = 0; v < V; v++)
			edges[v].clear();
	}
	return 0;
}