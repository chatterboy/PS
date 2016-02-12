#include <cstdio>
#include <vector>
using namespace std;

vector<int> squares;

int howManyWays(int n, int m, int k) {
	if (n < 0 || m < 0 || k < 0) return 0;
	if (n == 0) return 1;
	return howManyWays(n, m, k - 1) + howManyWays(n - squares[k], m - 1, k);
}

int main() {
	for (int i = 1; i * i <= (1 << 15); i++)
		squares.push_back(i * i);

	int n;
	while (scanf("%d", &n), n) {
		printf("%d\n", howManyWays(n, 4, squares.size() - 1));
	}

	return 0;
}