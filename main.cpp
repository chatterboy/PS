#include <bits/stdc++.h>
using namespace std;

#define a first
#define b second

const int inf = 1e8;

int cache[2][50001][2];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		vector<pair<int,int>> bakedTime;
		for (int i = 0; i < N; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			bakedTime.push_back({a, b});
		}
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 50001; j++)
				for (int k = 0; k < 2; k++)
					cache[i][j][k] = inf;
		cache[0][bakedTime[0].a][0] = bakedTime[0].a;
		cache[0][bakedTime[0].b][1] = bakedTime[0].b;
		for (int pos = 1; pos < N; pos++) {
			for (int diff = 0; diff < 50001; diff++) {
				if (bakedTime[pos].b + diff < 50001)
					cache[pos % 2][diff][0] = min(cache[pos % 2][diff][0], cache[(pos - 1) % 2][bakedTime[pos].b + diff][0]);
				if (diff >= bakedTime[pos].a)
					cache[pos % 2][diff][0] = min(cache[pos % 2][diff][0], cache[(pos - 1) % 2][diff - bakedTime[pos].a][0] + bakedTime[pos].a);
				if (bakedTime[pos].a >= diff)
					cache[pos % 2][diff][0] = min(cache[pos % 2][diff][0], cache[(pos - 1) % 2][bakedTime[pos].a - diff][1] + diff);

				if (bakedTime[pos].a + diff < 50001)
					cache[pos % 2][diff][1] = min(cache[pos % 2][diff][1], cache[(pos - 1) % 2][bakedTime[pos].a + diff][1]);
				if (diff >= bakedTime[pos].b)
					cache[pos % 2][diff][1] = min(cache[pos % 2][diff][1], cache[(pos - 1) % 2][diff - bakedTime[pos].b][1] + bakedTime[pos].b);
				if (bakedTime[pos].b >= diff)
					cache[pos % 2][diff][1] = min(cache[pos % 2][diff][1], cache[(pos - 1) % 2][bakedTime[pos].b - diff][0] + diff);
			}
		}
		int sol = inf;
		for (int diff = 0; diff < 50001; diff++)
			sol = min(sol, min(cache[(N - 1) % 2][diff][0], cache[(N - 1) % 2][diff][1]));
		printf("%d\n", sol);
	}
	return 0;
}