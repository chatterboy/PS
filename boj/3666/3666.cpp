#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int tc, n, a[100];
char adj[100][101];
vector<int> find() {
	vector<int> vertex;
	for (int i = 0; i < n; i++)
		if (a[i] > 0) {
			bool border = false;
			for (int j = 0; j < n; j++)
				if (adj[i][j] == 'Y' && a[j] == 0)
					border = true;
			if (border) vertex.push_back(i);
		}
	int mins = n + 1;
	vector<int> ret;
	for (int i = 0; i < vertex.size(); i++) {
		if (mins == a[vertex[i]]) ret.push_back(vertex[i]);
		if (mins > a[vertex[i]]) {
			mins = a[vertex[i]];
			ret.clear();
			ret.push_back(vertex[i]);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) scanf("%s", adj[i]);
		vector<int> weakness = find();
		int ans = 0;
		for (int i = 0; i < weakness.size(); i++) {
			int t = 0;
			for (int u = 0; u < n; u++)
				if (adj[weakness[i]][u] == 'Y' && a[u] > 0) {
					bool chk = true;
					for (int v = 0; v < n; v++)
						if (adj[u][v] == 'Y' && a[v] == 0)
							chk = false;
					if (chk) t += a[u] - 1;
				}
			ans = max(ans, t + a[weakness[i]]);
		}
		printf("%d\n", ans);
	}
}