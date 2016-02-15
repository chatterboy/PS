#include <cstdio>
#include <cstring>

int n, k;
int a[1000];
int parent[1000];
int levelId[1000];

int main() {
	while (scanf("%d%d", &n, &k), n | k) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		parent[0] = 0;
		int nowparent = -1;
		for (int i = 1; i < n; i++) {
			if (a[i] - a[i - 1] > 1) nowparent++;
			parent[i] = nowparent;
		}
		levelId[0] = 0;
		for (int i = 1; i < n; i++) {
			levelId[i] = levelId[parent[i]] + 1;
		}
		int where = 0;
		for (; where < n; where++) if (a[where] == k) break;
		int sol = 0;
		for (int i = 0; i < n; i++)
			if (parent[i] != parent[where] && levelId[i] == levelId[where] && parent[parent[i]] == parent[parent[where]]) sol++;
		printf("%d\n", sol);
		memset(a, 0, sizeof(a));
		memset(levelId, 0, sizeof(levelId));
		memset(parent, 0, sizeof(parent));
	}
	return 0;
}