#include <bits/stdc++.h>
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

			parent[s].first = s;
			q.push(s);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int i = 0; i < edges[u].size(); i++) {
					Edge *uv = edges[u][i];
					int v = uv->rev->target;
//					if (uv->cap == 0) continue;
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

int in(int i) { return i; }
int out(int i) { return i + 200; }

AdmondsKarp ak;
vector<bool> visited;
bool visitCut(int here) {
	visited[here] = true;
	for (int i = 0; i < ak.edges[here].size(); i++) {
		Edge *uv 
		int there = ak.edges[here][i]->target;
		if (ak.edges[there][i]->residual() > 0 && !visited[there])
			visitCut(there);
	}
}
bool visitCut(int v) {
	visitCut[v] = true;
}

int main() {
	ak = AdmondsKarp(400);
	int INF = ak.INF;
	int n, m;
	scanf("%d%d", &n, &m);
	int src, sink;
	scanf("%d%d", &src, &sink);
	src--, sink--;
	for (int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		ak.addEdge(in(i), out(i), c);
	}
	for (int i = 0; i < m; i++) {
		int v, w;
		scanf("%d%d", &v, &w);
		v--, w--;
		ak.addEdge(out(v), in(w), INF);
		ak.addEdge(out(w), in(v), INF);
	}
	ak.maxFlow(in(src), out(sink));
	visited = vector<bool>(400, false);
	visitCut(in(src));
	for (int i = 0; i < n; i++)
		if (visited[in(i)] && !visited[out(i)])
			printf("%d ", i);
}