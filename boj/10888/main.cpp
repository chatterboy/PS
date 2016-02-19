#include <cstdio>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> size;
	UnionFind(int n) : parent(n), size(n, 1) {
		n = parent.size();
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int v) {
		if (v == parent[v]) return v;
		return parent[v] = find(parent[v]);
	}
	void merge(int v, int w) {
		v = find(v);
		w = find(w);
		if (v != w) {
			parent[w] = v;
			size[v] += size[w];
		}
	}
	int length(int v) {
		return size[find(v)];
	}
};

int main() {
	int V;
	scanf("%d", &V);
	UnionFind uf(V);
	long long sol1 = 0, sol2 = 0;
	for (int i = 1; i < V; i++) {
		int v;
		scanf("%d", &v);
		v--;

		long long A = uf.length(v);
		long long B = uf.length(v + 1);
		sol1 += A * B;
		for (int j = 0; j < B; j++)
			sol2 += A * (A + 1) / 2 + A * j;

		printf("%lld %lld\n", sol1, sol2);

		uf.merge(v, v + 1);
	}
	return 0;
}