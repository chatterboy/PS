// ac
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int id[6];
	string w[6];
	for (int i = 0; i < 6; i++) {
		id[i] = i;
		cin >> w[i];
	}
	do {
		bool valid = true;
		for (int i = 3; i < 6; i++)
			if (w[id[i]][0] != w[id[0]][i-3] ||
				w[id[i]][1] != w[id[1]][i-3] ||
				w[id[i]][2] != w[id[2]][i-3]) {
				valid = false;
				break;
			}
		if (valid) {
			for (int i = 0; i < 3; i++)
				cout << w[id[i]] << '\n';
			exit(0);
		}
	} while (next_permutation(id, id + 6));
	cout << 0 << '\n';
}