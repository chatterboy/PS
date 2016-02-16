#include <cstdio>
#include <cctype>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

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

	AdmondsKarp(int V) : V(V) {}

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

int in(char c) {
	if (islower(c)) return c - 'a' + 26;
	return c - 'A';
}

int out(char c) {
	if (islower(c)) return c - 'a' + 78;
	return c - 'A' + 52;
}

int main() {
	int N;
	scanf("%d\n", &N);

	AdmondsKarp solve(104);

	for (int i = 0; i < N; i++) {
		char a, b;
		int c;
		scanf("%c %c %d\n", &a, &b, &c);
		solve.addEdge(out(a), in(b), c);
		solve.addEdge(out(b), in(a), c);
	}
	for (int i = 0; i < 26; i++) {
		solve.addEdge(in(i + 'A'), out(i + 'A'), INF);
		solve.addEdge(in(i + 'a'), out(i + 'a'), INF);
	}

	printf("%d", solve.maxFlow(in('A'), out('Z')));
	return 0;
}