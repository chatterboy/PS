// ac
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, cid[2500], hid[2500];
char correct[2500][16], haejoen[2500][16];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cid[i] = i;
		scanf("%s", correct[i]);
	}
	for (int i = 0; i < n; i++) scanf("%s", haejoen[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (strcmp(haejoen[i], correct[j]) == 0) hid[i] = j;
	int swaps = 0;
	for (int i = n-1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if (hid[j] > hid[j+1]) {
				swaps++;
				swap(hid[j], hid[j+1]);
			}
	int total = n*(n-1)/2;
	printf("%d/%d", total-swaps, total);
}