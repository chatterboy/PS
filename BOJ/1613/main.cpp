#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<vector<int>> dist(n, vector<int>(n, inf));
	vector<vector<int>> b_dist(n, vector<int>(n, inf));
	for (int i = 0; i < k; i++) {
		int v, w;
		scanf("%d%d", &v, &w);
		--v, --w;
		dist[v][w] = b_dist[w][v] = 1;
	}
	for (int k = 0; k < n; k++)
		for (int v = 0; v < n; v++)
			for (int w = 0; w < n; w++) {
				dist[v][w] = min(dist[v][w], dist[v][k] + dist[k][w]);
				b_dist[v][w] = min(b_dist[v][w], b_dist[v][k] + b_dist[k][w]);
			}
	int s;
	scanf("%d", &s);
	while (s--) {
		int v, w;
		scanf("%d%d", &v, &w);
		--v, --w;
		if (dist[v][w] < inf || b_dist[v][w] < inf) {
			if (dist[v][w] < inf)
				puts("-1");
			else {
				puts("1");
			}
		} else
			puts("0");
	}
	return 0;
}