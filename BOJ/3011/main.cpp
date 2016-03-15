#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> son(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &son[i]);
	int A, B;
	cin >> A >> B;
	sort(son.begin(), son.end());
	for (int i = 1; i < N; i++)
	return 0;
}