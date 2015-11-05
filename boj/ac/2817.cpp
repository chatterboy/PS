// ac
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct _um {
	int id;
	double val;
	_um(int id, double val) : id(id), val(val) {}
};
int x, n, ans[10];
string name[10];
vector<_um> seq;
bool cmp(const _um &a, const _um &b) { return a.val > b.val; }
int main() {
	cin >> x >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> name[i] >> t;
		if (0.05 * x > (double)t) { ans[i] = -1; continue; }
		for (int y = 1; y < 15; y++)
			seq.push_back(_um(i, (double)t / y));
	}
	sort(seq.begin(), seq.end(), cmp);
	for (int i = 0; i < 14; i++) {
		ans[seq[i].id]++;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (name[i] < name[j]) {
				swap(name[i], name[j]);
				swap(ans[i], ans[j]);
			}
	for (int i = 0; i < n; i++)
		if (ans[i] != -1) cout << name[i] << ' ' << ans[i] << '\n';
}