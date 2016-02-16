#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

struct AdmondsKarp {
	struct Edge {
		int target;
		int cap;
		int flow;
		Edge *rev;
		int residual() { return cap - flow; }
	};

	static const int INF = 1e9;
	static const int MAXV = 10000;

	int V;
	vector<Edge*> edges[MAXV];

	AdmondsKarp(int V = 0) : V(V) {}

	void addEdge(int u, int v, int cap) {
		Edge *uv = new Edge();
		Edge *vu = new Edge();

		uv->target = u;
		uv->cap = cap;
		uv->flow = 0;
		uv->rev = vu;

		vu->target = v;
		vu->cap = 0;
		vu->flow = 0;
		vu->rev = uv;

		edges[u].push_back(uv);
		edges[v].push_back(vu);
	}

	int maxFlow(int s, int e) {
		int ret = 0;
		for (;;) {
			vector<pair<int, Edge*>> parent(V, pair<int, Edge*>(-1, NULL));
			queue<int> q;
			q.push(s);
			parent[s].first = s;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int i = 0; i < edges[u].size(); i++) {
					Edge *uv = edges[u][i];
					int v = uv->rev->target;
					if (uv->residual() > 0 && parent[v].first == -1) {
						parent[v] = pair<int, Edge*>(u, uv);
						q.push(v);
					}
				}
			}
			if (parent[e].first == -1) break;
			int f = INF;
			for (int v = e; v != s; v = parent[v].first) {
				Edge *uv = parent[v].second;
				f = min(f, uv->residual());
			}
			ret += f;
			for (int v = e; v != s; v = parent[v].first) {
				Edge *uv = parent[v].second;
				uv->flow += f;
				uv->rev->flow -= f;
			}
		}
		return ret;
	}

	~AdmondsKarp() {
		for (int v = 0; v < V; v++) {
			for (int i = 0; i < edges[v].size(); i++)
				delete edges[v][i];
			edges[v].clear();
		}
	}
};

int in(int u) {
	return u - 1;
}

int out(int u) {
	return u + 399;
}

int main() {
	AdmondsKarp solve(800);
	int INF = AdmondsKarp().INF;
	int N, P;
	scanf("%d%d", &N, &P);
	for (int i = 0; i < P; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		solve.addEdge(out(u), in(v), INF);
		solve.addEdge(out(v), in(u), INF);
	}
	solve.addEdge(in(1), out(1), INF);
	solve.addEdge(in(2), out(2), INF);
	for (int v = 3; v <= N; v++) {
		solve.addEdge(in(v), out(v), 1);
	}
	printf("%d", solve.maxFlow(in(1), out(2)));
	return 0;
}