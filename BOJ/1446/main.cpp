#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int INF = 1e9;

int N, D;
vector<vector<pii>> edges;
vector<int> dist;

void dijkstra(int src) {
	dist = vector<int>(D + 1, INF);
	priority_queue<pii> pq;
	dist[src] = 0;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < edges[now].size(); i++) {
			int next = edges[now][i].first;
			int nextCost = cost + edges[now][i].second;
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &D);
	edges.resize(D + 1);
	for (int i = 0; i < N; i++) {
		int S, E, L;
		scanf("%d%d%d", &S, &E, &L);
		edges[S].push_back(make_pair(E, L));
	}
	for (int i = 0; i < D; i++)
		edges[i].push_back(make_pair(i + 1, 1));
	dijkstra(0);
	printf("%d", dist[D]);
	return 0;
}