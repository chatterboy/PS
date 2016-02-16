#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1e9;
const int MAXN = 500;

int N, M;
vector<pair<int,int>> edges[MAXN];

vector<int> shortestPath(int src) {
	vector<int> upper(N, INF);
	upper[src] = 0;
	bool updated;
	for (int iter = 0; iter < N; iter++) {
		updated = false;
		for (int u = 0; u < N; u++)
			for (int i = 0; i < edges[u].size(); i++) {
				int v = edges[u][i].first;
				int c = edges[u][i].second;
				if (upper[v] > upper[u] + c) {
					upper[v] = upper[u] + c;
					updated = true;
				}
			}
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		u--, v--;
		edges[u].push_back(make_pair(v, c));
	}
	vector<int> dist = shortestPath(0);
	if (dist.empty()) printf("-1");
	else
		for (int i = 1; i < N; i++)
			printf("%d\n", dist[i] == INF ? -1 : dist[i]);
	return 0;
}