#include <cstdio>
#include <string>
#include <map>
using namespace std;

int N, M, K;
char grid[51][51];
map<string,int> tables;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", grid[i]);
	scanf("%d", &K);
	for (int i = 0; i < N; i++) tables[string(grid[i])]++;
	int sol = 0;
	for (auto content : tables) {
		int zeros = 0;
		for (auto ch : content.first)
			if (ch == '0') zeros++;
		if (zeros <= K && !((K - zeros) & 1))
			sol = max(sol, content.second);
	}
	printf("%d", sol);
}