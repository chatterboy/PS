#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXN 20000

int N, M;
vector<int> edges[MAXN];
int vcnt, ccnt;
int visited[MAXN], finished[MAXN], sccId[MAXN];
stack<int> st;

int node(int u) {
	return abs(u) - 1 + (u < 0 ? N : 0);
}
int dfs(int u) {
	int ret = visited[u] = vcnt++;
	st.push(u);
	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i];
		if (visited[v] == -1)
			ret = min(ret, dfs(v));
		else if (visited[v] < visited[u] && sccId[v] == -1)
			ret = min(ret, visited[v]);
	}
	if (ret == visited[u]) {
		for (;;) {
			int t = st.top(); st.pop();
			sccId[t] = ccnt;
			if (t == u) break;
		}
		ccnt++;
	}
	finished[u] = 1;
	return ret;
}
void scc() {
	for (int i = 0; i < N; i++)
		visited[i] = finished[i] = sccId[i] = -1;
	for (int i = 0; i < N; i++)
		if (visited[i] == -1) dfs(i);
}
int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < M; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[node(-u)].push_back(node(v));
		edges[node(-v)].push_back(node(u));
	}
	N *= 2;
	scc();
	bool valid = true;
	for (int i = 0; i < N / 2; i++)
		valid &= sccId[i] != sccId[i + N / 2];
	printf("%s", (valid ? "^_^" : "OTL"));
	return 0;
}