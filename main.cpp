#include <bits/stdc++.h>
using namespace std;

struct LongLong {
	vector<int> v;

	LongLong(int d) {
		v.push_back(d);
	}

	LongLong(vector<int> &v) : v(v) {}

	void setToSameDigit(vector<int> &v1, vector<int> &v2) {
		if (v1.size() < v2.size())
			swap(v1, v2);
		int n = v1.size() - v2.size();
		for (int i = 0; i < n; i++)
			v2.push_back(0);
	}

	void normalize() {
		v.push_back(0);
		int n = v.size();
		for (int i = 0; i < n - 1; i++) {
			v[i + 1] += v[i] / 10;
			v[i] %= 10;
		}
		while (v.back() == 0)
			v.pop_back();
	}

	LongLong operator + (const LongLong &b) {
		vector<int> v1(v);
		vector<int> v2(b.v);

		setToSameDigit(v1, v2);

		int n = v1.size();
		vector<int> v3(n, 0);
		for (int i = 0; i < n; i++)
			v3[i] = v1[i] + v2[i];

		LongLong c(v3);
		c.normalize();

		return c;
	}

	void print() {
		int n = v.size();
		for (int i = n - 1; i >= 0; i--)
			printf("%d", v[i]);
	}
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> score(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> score[i][j];
	vector<vector<LongLong>> cache(n, vector<LongLong>(n, 0));
	cache[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (score[i][j] == 0) continue;
			if (i + score[i][j] < n)
				cache[i + score[i][j]][j] = cache[i + score[i][j]][j] + cache[i][j];
			if (j + score[i][j] < n)
				cache[i][j + score[i][j]] = cache[i][j + score[i][j]] + cache[i][j];
		}
	cache[n - 1][n - 1].print();
	return 0;
}