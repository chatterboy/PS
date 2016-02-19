// T[node][k] = node가 포함된 분자의 원자 수가 k개 일 때, 분해반응의 최소횟수

// 이렇게 하면, 서브트리에 대해서 지수시간이 걸린다.
// 왜냐하면 서브트리의 수가 n개 이면 각 서브트리와 결합을 해제 여부를 판단해야
// 하기 때문에 2^n

// 이걸 사용하면 O(n^2 * 2^n)이 된다.

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAXN = 150;

FILE *fout = fopen("output.txt", "w");

vector<int> edges[MAXN];
vector<bool> visited;
vector<int> nodesIn; // i번째 노드를 루트로 하는 서브트리에 포함되는 노드의 개수

int dfs(int u, vector<bool> &visited) {
	visited[u] = true;
	int ret = 1;
	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i];
		if (!visited[v])
			ret += dfs(v, visited);
	}
	visited[u] = false;
	return nodesIn[u] = ret;
}

int solve(int v, int p, int t) {
	fprintf(fout, "%d %d %d\n", v, p, t);
	if (t < 0) return 0;
	if (edges[v].empty()) {
		if ()
	}
	visited[v] = true;
	int ret = min(solve(v, p, t - 1),
				  solve(v, p - nodesIn[edges[v][t]], t - 1) + solve(edges[v][t], nodesIn[edges[v][t]], edges[edges[v][t]].size() - 1) + 1);
	visited[v] = false;
	return ret;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int v = 1; v < N; v++) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	nodesIn.resize(N);
	visited = vector<bool>(N, false);

	dfs(0, visited);

	for (int v = 0; v < N; v++)
		printf("%d ", nodesIn[v]);
	puts("");

	printf("%d", solve(0, nodesIn[0], edges[0].size() - 1));

	return 0;
}