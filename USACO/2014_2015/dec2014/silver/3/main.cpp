// WA

// T 시간이 지났을 때, 남아있는 그룹의 수

// N <= 10^6

// 1. 모두 서로 다른 위치에서 시작한다.
// 2. 증가순으로 주어진다.

#include <bits/stdc++.h>
using namespace std;

#define p first
#define v second

int N, T;
vector<pair<int,int>> D;

int main() {
	scanf("%d%d", &N, &T);
	D.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &D[i].p, &D[i].v);
	int sol = 0;
	for ()
	printf("%d", sol);
	return 0;
}