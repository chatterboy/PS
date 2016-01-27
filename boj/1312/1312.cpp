#include <cstdio>

int main() {
	int A, B, N, sol;
	scanf("%d%d%d", &A, &B, &N);
	A = (A % B) * 10;
	for (int i = 1; i <= N; i++) {
		sol = A / B;
		A = (A % B) * 10;
	}
	printf("%d", sol);
}