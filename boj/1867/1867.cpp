#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 500;

int n, k;
int grid[maxn][maxn];
int nextMatch[maxn];
bool visited[maxn];
vector<int> edges[maxn];

bool canMatch(int here)
{
	if (visited[here]) return false;
	visited[here] = true;
	for (int i = 0; i < edges[here].size(); i++)
	{
		int next = edges[here][i];
		if (nextMatch[next] == -1 || canMatch(nextMatch[next]))
		{
			nextMatch[next] = here;
			return true;
		}
	}
	return false;
}
// output: the size of the maximum bipartite matching in bipartite graph
int maximumBipartiteMatching()
{
	for (int next = 0; next < n; next++) nextMatch[next] = -1;
	int ret = 0;
	for (int here = 0; here < n; here++)
	{
		memset(visited, false, sizeof(visited));
		if (canMatch(here)) ret++;
	}
	return ret;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int r, c; scanf("%d%d", &r, &c);
		r--, c--;
		edges[r].push_back(c);
	}
	printf("%d", maximumBipartiteMatching());
}