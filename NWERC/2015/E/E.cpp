#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define maxn 2500

int n, m;
int counter = 0;
vector<long long> a, b;
vector<pair<int, long long>> c;
map<long long, int> maps;
vector<int> adj[maxn];
int nextMatch[maxn * 3], bMatch[maxn];
bool visited[maxn];

bool canMatch(int here)
{
	if (visited[here]) return false;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int next = adj[here][i];
		if (nextMatch[next] == -1 || canMatch(nextMatch[next]))
		{
			nextMatch[next] = here;
			bMatch[here] = next;
			return true;
		}
	}
	return false;
}

int maximumBipartiteMatching()
{
	for (int next = 0; next < m; next++) nextMatch[next] = -1;
	int ret = 0;
	for (int here = 0; here < n; here++)
	{
		memset(visited, false, sizeof(visited));
		if (canMatch(here)) ret++;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	a.resize(n), b.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i], &b[i]);
		auto p = maps.find(a[i] + b[i]);
		if (p == maps.end()) maps[a[i] + b[i]] = counter++;
		p = maps.find(a[i] - b[i]);
		if (p == maps.end()) maps[a[i] - b[i]] = counter++;
		p = maps.find(a[i] * b[i]);
		if (p == maps.end()) maps[a[i] * b[i]] = counter++;
		adj[i].push_back(maps[a[i] + b[i]]);
		adj[i].push_back(maps[a[i] - b[i]]);
		adj[i].push_back(maps[a[i] * b[i]]);
	}
	for (auto v : maps) c.push_back(make_pair(v.second, v.first));
	sort(c.begin(), c.end());
	m = c.size();
	int res = maximumBipartiteMatching();
	if (res != n) printf("impossible");
	else {
		for (int i = 0; i < n; i++) {
			printf("%lld ", a[i]);
			if (a[i] + b[i] == c[bMatch[i]].second) putchar('+');
			else if (a[i] - b[i] == c[bMatch[i]].second) putchar('-');
			else if (a[i] * b[i] == c[bMatch[i]].second) putchar('*');
			printf(" %lld = %lld\n", b[i], c[bMatch[i]].second);
		}
	}
}