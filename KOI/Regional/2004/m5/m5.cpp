#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxnm = 1001;

int n, m;
char A[maxnm], B[maxnm];
int cache[maxnm][maxnm];

void dp() {
	for (int i = 0; i <= n; i++) cache[i][0] = 0;
	for (int j = 0; j <= m; j++) cache[0][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cache[i][j] = 0;
			if (A[i] == B[j]) cache[i][j] = max(cache[i][j], cache[i-1][j-1]+3);
			if (A[i] != B[j]) cache[i][j] = max(cache[i][j], cache[i-1][j-1]-2);
			cache[i][j] = max(cache[i][j], cache[i-1][j]-2);
			cache[i][j] = max(cache[i][j], cache[i][j-1]-2);
		}
}
int maxSimilarity(int i, int j) { return cache[i][j]; }
void construct(int i, int j, string &solA, string &solB) {
	if (i < 1 || j < 1) return;
	int maxi, maxj, maxv = 0;
	if (A[i] == B[j] && maxSimilarity(i - 1, j - 1) + 3 > maxv) {
		maxv = maxSimilarity(i - 1, j - 1) + 3;
		maxi = i - 1, maxj = j - 1;
	}
	if (A[i] != B[j] && maxSimilarity(i - 1, j - 1) - 2 > maxv) {
		maxv = maxSimilarity(i - 1, j - 1) - 2;
		maxi = i - 1, maxj = j - 1;
	}
	if (maxSimilarity(i - 1, j) - 2 > maxv) {
		maxv = maxSimilarity(i - 1, j) - 2;
		maxi = i - 1, maxj = j;
	}
	if (maxSimilarity(i, j - 1) - 2 > maxv) {
		maxv = maxSimilarity(i, j - 1) - 2;
		maxi = i, maxj = j - 1;
	}
	if (maxv == 0) return;
	construct(maxi, maxj, solA, solB);
	if (maxi == i - 1 && maxj == j - 1) {
		solA.push_back(A[i]), solB.push_back(B[j]);
	} else if (maxi == i - 1) {
		solA.push_back(A[i]);
	} else {
		solB.push_back(B[j]);
	}
}
int main() {
	scanf("%d%s%d%s", &n, A + 1, &m, B + 1);
	dp();
	/*
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) printf("%3d ", cache[i][j]);
		puts("");
	}
	*/
	int maxi, maxj, maxv = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (cache[i][j] > maxv) {
				maxv = cache[i][j];
				maxi = i, maxj = j;
			}
	printf("%d\n", maxv);
	string solA, solB;
	construct(maxi, maxj, solA, solB);
	printf("%s\n%s", solA.c_str(), solB.c_str());
}