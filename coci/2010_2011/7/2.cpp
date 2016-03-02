#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	scanf("%d%d\n", &N, &K);
	vector<char> wheel(N, '?');
	int p = 0;
	for (int k = 0; k < K; k++) {
		int t;
		char c;
		scanf("%d %c\n", &t, &c);
		p = (p + t) % N;
		if (wheel[p] == '?') {
			wheel[p] = c;
		} else if (c != wheel[p]) {
			putchar('!');
			return 0;
		}
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		int t = 0;
		for (int i = 0; i < N; i++)
			t += wheel[i] == c;
		if (t > 1) {
			putchar('!');
			return 0;
		}
	}
	for (int i = p; i >= 0; i--)
		putchar(wheel[i]);
	for (int i = N - 1; i > p; i--)
		putchar(wheel[i]);
	return 0;
}