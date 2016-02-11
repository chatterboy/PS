// 현재 dp에서 A's weight를 없애고
// T[pos][A팀에 있는 사람 수]일 때 0에 가장 가까운 수
// 로 정의할수 있으면 가장 좋다.
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, total, w[101];
int cache[101][45001];

int nearlyEqual(int pos, int AsWeight) {
	if (pos > N) {
		return abs(2 * AsWeight - total);
	}
	int &ret = cache[pos][AsWeight];
	if (ret != -1) return ret;
	return ret = min(nearlyEqual(pos + 1, AsWeight), nearlyEqual(pos + 1, AsWeight + w[pos]));
}

void construct(int pos, int AsWeight) {
	if (pos > N) {
		int first = AsWeight, second = total - AsWeight;
		if (first > second) swap(first, second);
		printf("%d %d", first, second);
		return;
	}
	if (nearlyEqual(pos + 1, AsWeight) < nearlyEqual(pos + 1, AsWeight + w[pos])) {
		construct(pos + 1, AsWeight);
	} else {
		construct(pos + 1, AsWeight + w[pos]);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &w[i]);
		total += w[i];
	}
	memset(cache, -1, sizeof(cache));
	nearlyEqual(1, 0);
	construct(1, 0);
	return 0;
}