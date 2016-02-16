#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1e9;
const int MAXN = 501;

int N, M, W;
vector<pair<int, int>> edges[MAXN];

void addEdge(int u, int v, int c) { edges[u].push_back(make_pair(v, c)); }

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
	int tc; scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d%d", &N, &M, &W);
		for (int i = 0; i < M; i++) {
			int u, v, c; scanf("%d%d%d", &u, &v, &c);
			addEdge(u, v, c), addEdge(v, u, c);
		}
		for (int i = 0; i < W; i++) {
			int u, v, c; scanf("%d%d%d", &u, &v, &c);
			addEdge(u, v, -c);
		}
		N++;
		for (int i = 1; i < N; i++)
			addEdge(0, i, 0);
		//
		vector<int> dist = shortestPath(0);
		if (dist.empty()) puts("YES");
		else puts("NO");
		//
		for (int i = 0; i < N; i++)
			edges[i].clear();
	}
	return 0;
}