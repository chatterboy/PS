// wa

#include <bits/stdc++.h>
using namespace std;

vector<bool> prime;

int main() {
	prime.resize(1000001, false);
	for (int i = 2; i <= 1000000; i++) {
		bool valid = true;
		for (int j = 2; j * j <= i; j++)
			if (i % j == 0) {
				valid = false;
				break;
			}
		if (valid)
			prime[i] = true;
	}
	int L, U;
	while (scanf("%d%d", &L, &U), L >= 0 && U >= 0) {
		int x = 0, y = 0;
		for (int n = L; n <= U; n++)
			if (prime[n]) {
				x++;
				if ((n - 1) % 4 == 0 && )
			}
	}
	return 0;
}