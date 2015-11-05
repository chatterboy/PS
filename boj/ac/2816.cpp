// ac
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, idx[100];
string channel[100];
void f(string name, int p) {
	int i = 0;
	while (name != channel[idx[i]]) { i++; putchar('1'); }
	while (p != i) { i--; swap(idx[i], idx[i+1]); putchar('4'); }
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		idx[i] = i;
		cin >> channel[i];
	}
	f("KBS1", 0);
	f("KBS2", 1);
}