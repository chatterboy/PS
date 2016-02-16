#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAXV = 802;

struct Edge {
	int target;
	int capacity;
	int cost;
	int flow;
	Edge *reverse;
	int residualCapacity() { return capacity - flow; }
};

int V, E;
vector<Edge*> edges[MAXV];
vector<int> pot;

void addEdge(int u, int v, int capacity, int cost) {
	Edge *uv = new Edge();
	Edge *vu = new Edge();

	uv->target = u;
	uv->capacity = capacity;
	uv->cost = cost;
	uv->flow = 0;
	uv->reverse = vu;

	vu->target = v;
	vu->capacity = 0;
	vu->cost = -cost; // 비용추가를 유의해야 한다... 음수 사이클 생겨서 이상해짐 ;;
	vu->flow = 0;
	vu->reverse = uv;

	edges[u].push_back(uv);
	edges[v].push_back(vu);
}

vector<int> bellmanFord(int src) {
	vector<int> upper(V, INF);
	upper[src] = 0;
	bool updated;
	for (int iter = 0; iter < V; iter++) {
		updated = false;
		for (int u = 0; u < V; u++)
			for (int i = 0; i < edges[u].size(); i++) {
				Edge *uv = edges[u][i];
				int v = uv->reverse->target;
				int cost = uv->cost;
				if (uv->capacity == 0) continue;
				if (upper[v] > upper[u] + cost) {
					upper[v] = upper[u] + cost;
					updated = true;
				}
			}
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}

void reducePots() {
	for (int u = 0; u < V; u++)
		for (int i = 0; i < edges[u].size(); i++) {
			Edge *uv = edges[u][i];
			int v = uv->reverse->target;
			printf("%d->%d : %d\n", u, v, uv->cost);
		} puts("");
	for (int u = 0; u < V; u++)
		for (int i = 0; i < edges[u].size(); i++) {
			Edge *uv = edges[u][i];
			int v = uv->reverse->target;
			uv->cost = uv->cost + pot[u] - pot[v];
		}
	for (int u = 0; u < V; u++)
		for (int i = 0; i < edges[u].size(); i++) {
			Edge *uv = edges[u][i];
			int v = uv->reverse->target;
			printf("%d->%d : %d\n", u, v, uv->cost);
		} puts("");
}

// Successive Shortest Path algorithm in MCMF(Min-cost Flow problem)
int main() {
	// input a transportation graph and transform to transformed graph
	scanf("%d%d", &V, &E);
	for (int u = 0; u < V; u++) {
		int p; scanf("%d", &p);
		if (p > 0)
			addEdge(0, 2 + u, p, 0);
		if (p < 0)
			addEdge(2 + u, 1, -p, 0);
	}
	for (int e = 0; e < E; e++) {
		int u, v, capacity, cost; scanf("%d%d%d%d", &u, &v, &capacity, &cost);
		u++, v++;
		addEdge(u, v, capacity, cost);
	}
	V += 2;
	// use Bellmand-Ford's algorithm to establish potentials of node i
	pot = bellmanFord(0);
	for (int u = 0; u < V; u++) printf("%2d ", u); puts("");
	for (auto p : pot) printf("%2d ", p); puts("");
	// reduce cost with potentials
	reducePots();
	// 다익스트라를 이용해서 최단경로를 찾는데 여기서는 다르게 찾는다.
	// 최단경로를 찾지만 인접한 경로에 대해서 augmentation을 확인하고
	// 즉, 잔여용량 > 0인 경우를 고려한다. 
	return 0;
}