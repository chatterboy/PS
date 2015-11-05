// ac
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> aa(a);
	vector<bool> chk(n, false);
	sort(aa.begin(), aa.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == aa[j] && !chk[j]) {
				chk[j] = true;
				printf("%d ", j);
				break;
			}
		}
	}
}