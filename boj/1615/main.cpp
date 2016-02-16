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
};

int main() {
	return 0;
}