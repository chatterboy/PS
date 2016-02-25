#include <bits/stdc++.h>
using namespace std;

#define a first
#define b second

const int inf = 1e9;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int N;
		scanf("%d", &N);
		vector<pair<int,int>> cookie = vector<pair<int,int>>(N);
		for (int i = 0; i < N; i++)
			scanf("%d%d", &cookie[i].a, &cookie[i].b);
		vector<vector<vector<int>>> cache = vector<vector<vector<int>>>(N, vector<vector<int>>(50001, vector<int>(2, 0)));
		cache[0][0][0] = cookie[0].b;
		cache[0][0][1] = cookie[0].a;
		for (int pos = 1; pos < N; pos++) {
			for (int diff = 0; diff <= 30000; diff++) {
//			for (int diff = 30000; diff >= 0; diff--) {
				// A
				cache[pos][diff][0] = cache[pos - 1][diff + cookie[pos].a][0] + cookie[pos].a;
				if (diff < cookie[pos].b)
					cache[pos][diff][0] = min(cache[pos][diff][0],
											  cache[pos - 1][cookie[pos].b - diff][1] + cookie[pos].b - diff);
				else
					cache[pos][diff][0] = min(cache[pos][diff][0],
											  cache[pos - 1][diff - cookie[pos].b][0]);
				// B
				cache[pos][diff][1] = cache[pos - 1][diff + cookie[pos].b][1] + cookie[pos].b;
				if (diff < cookie[pos].a)
					cache[pos][diff][1] = min(cache[pos][diff][1],
											  cache[pos - 1][cookie[pos].a - diff][0] + cookie[pos].a - diff);
				else
					cache[pos][diff][1] = min(cache[pos][diff][1],
											  cache[pos - 1][diff - cookie[pos].a][1]);
			}
		}
		printf("%d\n", min(cache[N - 1][0][0], cache[N - 1][0][1]));
	}
}
/*
int N;
vector<pair<int,int>> cookie;

int minTime(int pos, int diff, int oven) {
	if (diff > 50000) return inf;
	if (pos < 0) return 0;
	int ret = inf;
	if (oven == 0) {
		ret = min(ret, minTime(pos - 1, diff + cookie[pos].a, oven) + cookie[pos].a);
		if (diff < cookie[pos].b)
			ret = min(ret, minTime(pos - 1, cookie[pos].b - diff, 1 - oven) + cookie[pos].b - diff);
		else
			ret = min(ret, minTime(pos - 1, diff - cookie[pos].b, oven));
	} else {
		ret = min(ret, minTime(pos - 1, diff + cookie[pos].b, oven) + cookie[pos].b);
		if (diff < cookie[pos].a)
			ret = min(ret, minTime(pos - 1, cookie[pos].a - diff, 1 - oven) + cookie[pos].a - diff);
		else
			ret = min(ret, minTime(pos - 1, diff - cookie[pos].a, oven));
	}
	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &N);
		cookie = vector<pair<int,int>>(N);
		for (int i = 0; i < N; i++)
			scanf("%d%d", &cookie[i].a, &cookie[i].b);
		printf("%d\n", min(minTime(N - 1, 0, 0), minTime(N - 1, 0, 1)));
	}
	return 0;
}
*/