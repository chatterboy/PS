#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <utility>
using namespace std;
#define inf 987654321
int tc, n, m, ans[500];
vector<int> dist;
vector<int> parent[500];
vector<pair<int, int> > adj[500];
priority_queue<pair<int, int> > pq;
void dijkstra(int src) {
	dist = vector<int>(n, inf);
	dist[src] = 0;
	pq = priority_queue<pair<int, int> > ();
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
				parent[there].clear();
				parent[there].push_back(here);
			} else if (dist[there] == nextDist)
				parent[there].push_back(here);
		}
	}
}
bool visited[500];
bool dfs(int des, int here) {
	if (des == here) return true;
	if (visited[here]) return false;
	visited[here] = true;
	for (int i = 0; i < parent[here].size(); i++)
		if (dfs(des, parent[here][i]))
			return true;
	return false;
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &tc);
	for (int tcn = 1; tcn <= tc; tcn++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) adj[i].clear();
		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			u--; v--;			
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
		// solve...
		int sz=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) parent[j].clear();
			dijkstra(i);
			for (int j = 0; j < n; j++) {
				// i <- j에 대한 모든 경로에 대해서
				for (int k = 0; k < n; k++)
					if (k != i && k != j && ans[k] == 0) {
						for (int ii = 0; ii < n; ii++) visited[ii] = false;
						visited[k] = true;
						// k가 단절점이라면 dfs(i,j)는
						// 불가능하다.
						if (!dfs(i, j)) {
							sz++;
							ans[k] = 1;
						}
					}
			}
		}
		printf("Case #%d\n", tcn);
		printf("%d", sz);
		for (int i = 0; i < n; i++)
			if (ans[i]) printf(" %d", i+1);
		putchar('\n');
		memset(ans, 0, sizeof(ans));
	}
}