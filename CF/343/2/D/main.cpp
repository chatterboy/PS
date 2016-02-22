// WA

// 케이크들을 여러개 쌓아올렸을 때 케이크들의 부피합의 최대값

// i번째 케이크에 대해서
// 1 테이블 위에 올릴 수 있다.
// 2 j번째 케이크 위에 올릴 수 있다.
//		2.1 j < i
//		2.2 vol[j] < vol[i]

// D[i] = [1...i]

// 쉽게 생각할 수 있는 방법으로는 O(N^2)

#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846

const int MAXN = 101010;

int N;
vector<pair<long long,int>> V;
vector<long long> D;

long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
    if (left > nodeRight || right < nodeLeft) return 0;
    if (nodeLeft >= left && nodeRight <= right) return D[node];
    int mid = (nodeLeft + nodeRight) / 2;
    return max(query(left, right, 2 * node, nodeLeft, mid),query(left, right, 2 * node + 1, mid + 1, nodeRight));
}
 
long long update(int index, long long value, int node, int nodeLeft, int nodeRight) {
    if (index > nodeRight || index < nodeLeft) return D[node];
    if (nodeLeft == nodeRight) return D[node] = value;
    int mid = (nodeLeft + nodeRight) / 2;
    return D[node] = max(update(index, value, 2 * node, nodeLeft, mid),update(index, value, 2 * node + 1, mid + 1, nodeRight));
}

int main() {
	scanf("%d", &N);
	V.resize(N);
	for (int i = 0; i < N; i++) {
		int r, h;
		scanf("%d%d", &r, &h);
		V[i] = make_pair((long long)r * r * h, i);
	}
	sort(V.begin(), V.end());
	D.resize(8 * MAXN);
	for (int i = 0; i < N; i++) {
		long long vol = V[i].first;
		int id = V[i].second;
		long long val = query(1, id + 1, 1, 1, 100000) + vol;
		update(id + 1, val, 1, 1, 100000);
	}
	printf("%.10f", 1. * PI * query(1, N, 1, 1, 100000));
	return 0;
}