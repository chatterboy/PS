#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> numOfBinary(1024);
	for (int i = 0; i < N; i++) {
		long long t;
		scanf("%lld", &t);
		bool digits[10] = {false};
		while (t > 0) {
			digits[t % 10] = true;
			t /= 10;
		}
		t = 0;
		for (int b = 0; b < 10; b++)
			if (digits[b])
				t += (1 << b);
		numOfBinary[t]++;
	}
	long long sol = 0;
	for (int i = 1; i < 1024; i++) {
		if (numOfBinary[i] > 1)
			sol = sol + (long long)numOfBinary[i] * (numOfBinary[i] - 1) / 2;
		for (int j = i + 1; j < 1024; j++)
			if (i != j && (i & j))
				sol += (long long)numOfBinary[i] * numOfBinary[j];
	}
	printf("%lld", sol);
	return 0;
}