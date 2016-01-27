// T[node][k] = node가 포함된 분자의 원자 수가 k개 일 때, 분해반응의 최소횟수

// 이렇게 하면, 서브트리에 대해서 지수시간이 걸린다.
// 왜냐하면 서브트리의 수가 n개 이면 각 서브트리와 결합을 해제 여부를 판단해야
// 하기 때문에 2^n

// 이걸 사용하면 O(n^2 * 2^n)이 된다.

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;

FILE *fout = fopen("output.txt", "w");

const int MAXN = 151;

int N, M;
vector<int> edges[MAXN];
int noNodes[MAXN];
bool visited[MAXN];

int countNodes(int here) {
	visited[here] = true;
	int ret = 1;
	for (int i = 0; i < edges[here].size(); i++) {
		int there = edges[here][i];
		if (!visited[there]) ret += countNodes(there);
	}
	visited[here] = false;
	return noNodes[here] = ret;
}
int minDissolutions(int now, int child, int k) {
	if (edges[now].empty()) return 0;
	if (edges[now].size() > child) return 0;
	fprintf(fout, "%d %d %d\n", now, child, k);
	visited[now] = true;
	int a, b;
	if (!visited[edges[now][child]]) {
		a = minDissolutions(edges[now][child], 0, k) +
				minDissolutions(now, child + 1, k);
		b = minDissolutions(edges[now][child], 0, noNodes[edges[now][child]]) +
				minDissolutions(now, child + 1, k - noNodes[edges[now][child]]) + 1;
	}
	visited[now] = false;
	return min(a, b);
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		edges[a].push_back(b); edges[b].push_back(a);
	}
	countNodes(1);
	for (int i = 1; i <= N; i++) fprintf(fout, "%d ", i); fprintf(fout, "\n");
	for (int i = 1; i <= N; i++) fprintf(fout, "%d ", noNodes[i]); fprintf(fout, "\n");
	printf("%d", minDissolutions(1, 0, noNodes[1]));
}