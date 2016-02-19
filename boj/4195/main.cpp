#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct UnionFind {
	int n;
	vector<int> parent;
	vector<int> size;
	UnionFind(int n) : parent(n), size(n, 1) {
		n = parent.size();
		for (int i = 0; i < n; i++)
			parent[i] =  i;
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
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int F;
		scanf("%d", &F);
		UnionFind uf(200000);
		int entryCounter = 0;
		map<string,int> entry;
		while (F--) {
			char name1[21] = {};
			char name2[21] = {};
			scanf("%s%s", name1, name2);
			if (entry.find(string(name1)) == entry.end())
				entry[string(name1)] = entryCounter++;
			if (entry.find(string(name2)) == entry.end())
				entry[string(name2)] = entryCounter++;
			int v = entry[string(name1)];
			int w = entry[string(name2)];
			uf.merge(v, w);
			printf("%d\n", uf.length(v));
		}
	}
	return 0;
}