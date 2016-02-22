#include <bits/stdc++.h>
using namespace std;

struct frame {
	int type; // 0: 보석, 1: 가방
	int w;
	int v;
};

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	vector<frame> vec;
	for (int i = 0; i < N; i++) {
		int M, V;
		scanf("%d%d", &M, &V);
		vec.push_back(frame{0, M, V});
	}
	for (int i = 0; i < K; i++) {
		int C;
		scanf("%d", &C);
		vec.push_back(frame{1, C, 0});
	}
	sort(vec.begin(), vec.end(), [](const frame &a, const frame &b){
		if (a.w == b.w)
			a.type < b.type;
		return a.w < b.w;
	});
	priority_queue<int> pq;
	long long sol = 0;
	for (int i = 0; i < vec.size(); i++) {
		frame fr = vec[i];
		if (fr.type == 0) {
			pq.push(fr.v);
		} else {
			if (!pq.empty()) {
				sol = sol + pq.top();
				pq.pop();
			}
		}
	}
	printf("%lld", sol);
	return 0;
}