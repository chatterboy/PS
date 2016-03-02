/*

6 4
15 80
8 230
10 100
17 200
20 75
26 80

8 230
10 100
15 80
17 200
20 75
26 80

*/

// D[i] = max(D[1], ... , D[k]) + cost[i]
/*
1)
for i = [0, N-1]
	D[i] = 0
	for j = [0, i)
		if H[i] - H[j] >= S
			D[i] = max(D[i], D[j] + cost[i])

2)
for i = [0, N-1]
	D[i] = 0
	for j = [0, k]
		D[i] = max(D[i], D[j] + cost[i])

3)
for i = [0, N)
	D[i] = cost[i]
	for j = [0, i)
		D[i] = max(D[i], D[j] + cost[i])

i, 		oooooxxxx
i+1, 	oooooooxx

O(N)에 하기 위해서
D[i]의 값은
1. D[i-1]
2. [k, k'] 에서의 최적값

E[i] = i번째 그림의 k값

for i = [0, N)
	D[i] = cost[i]
	D[i] = max(D[i], D[i-1])
	

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, S;
	scanf("%d%d", &N, &S);
	vector<pair<int,int>> pic(N);
	for (int i = 0; i < N; i++) {
		int h, c;
		scanf("%d%d", &h, &c);
		pic[i] = make_pair(h, c);
	}
	sort(pic.begin(), pic.end());
	vector<int> D(N);
	for (int i = 0; i < N; i++) {
		D[i] = pic[i].second;
		for (int j = 0; j < i; j++) {
			if (pic[i].first - pic[j].first < S)
				break;
			D[i] = max(D[i], D[j] + pic[i].second);
		}
	}
	printf("%d", D[N - 1]);
	return 0;
}
