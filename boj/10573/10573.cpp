#include <cstdio>
#include <cstring>

int n;
char a[81];
long long cache[81][10][2];

bool chk() {
	for (int i = 1; i <= n; i++) if (a[i] < a[i - 1]) return false;
	return true;
}

long long howMany(int pos, int previous, int state) {
	if (pos > n) {
		return 1;
	}
	long long &ret = cache[pos][previous][state];
	if (ret != -1) return ret;
	ret = 0;
	if (state == 0) {
		for (int x = previous; x < 10; x++)
			ret += howMany(pos + 1, x, state);
	} else {
		for (int x = previous; x <= (a[pos] - '0'); x++) {
			if (x == (a[pos] - '0')) ret += howMany(pos + 1, x, state);
			else ret += howMany(pos + 1, x, 1 - state);
		}
	}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		scanf("%s", a + 1);
		n = strlen(a + 1);
		if (!chk()) puts("-1");
		else {
			memset(cache, -1, sizeof(cache));
			long long sol = 0;
			for (int x = 0; x <= (a[1] - '0'); x++) {
				if (x == a[1] - '0') sol += howMany(2, x, 1);
				else sol += howMany(2, x, 0);
			}
			printf("%lld\n", sol - 1);
		}
		memset(a, 0, sizeof(a));
	}
	return 0;
}