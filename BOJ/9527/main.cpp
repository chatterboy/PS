#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

lld A, B;
vector<int> bA, bB;
int nA, nB;

void makeBinary(lld d, vector<int> &b) {
	while (d) {
		b.push_back(d % 2);
		d /= 2;
	}
}

void countNum(bA)

int main() {
	cin >> A >> B;
	makeBinary(A, bA);
	makeBinary(B, bB);
	for (int i = 0; i < bA.size(); i++) printf("%d", bA[i]); puts("");
	for (int i = 0; i < bB.size(); i++) printf("%d", bB[i]); puts("");
	nA = bA.size();
	nB = bB.size();
	
	return 0;
}