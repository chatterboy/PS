#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, R, G, B;
ll cache[11][101][101][101];

ll perm(int k) {
	ll ret = 1;
	for (int i = 2; i <= k; i++)
		ret *= i;
	return ret;
}

ll solve(int h, int r, int g, int b) {
	if (h > N) return 1;
	ll &ret = cache[h][r][g][b];
	if (ret != -1) return ret;
	ret = 0;
	int cand[] = {r, g, b};
	for (int i = 0; i < 3; i++)
		if (cand[i] >= h) {
			cand[i] -= h;
			ret += solve(h + 1, cand[0], cand[1], cand[2]);
			cand[i] += h;
		}
	if (h % 2 == 0) {
		int cand[] = {r, g, b};
		int cand2[][2] = {{0, 1}, {0, 2}, {1, 2}};
		for (int i = 0; i < 3; i++)
			if (cand[cand2[i][0]] >= h / 2 && cand[cand2[i][1]] >= h / 2) {
				cand[cand2[i][0]] -= h / 2, cand[cand2[i][1]] -= h / 2;
//				ret += perm(h) / ((h / 2) * (h / 2)) * solve(h + 1, cand[0], cand[1], cand[2]);
				ret += perm(h) / perm(h / 2) / perm(h / 2) * solve(h + 1, cand[0], cand[1], cand[2]); 
				cand[cand2[i][0]] += h / 2, cand[cand2[i][1]] += h / 2;
			}
	}
	if (h % 3 == 0) {
		if (r >= h / 3 && g >= h / 3 && b >= h / 3)
//			ret += perm(h) / ((h / 3) * (h / 3) * (h / 3)) * solve(h + 1, r - h / 3, g - h / 3, b - h / 3);
			ret += perm(h) / perm(h / 3) / perm(h / 3) / perm(h / 3) * solve(h + 1, r - h / 3, g - h / 3, b - h / 3);
	}
	return ret;
}

int main() {
	cin >> N >> R >> G >> B;
	memset(cache, -1, sizeof(cache));
	cout << solve(1, R, G, B);
	return 0;
}