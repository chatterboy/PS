// implementing to multiply of two big integers
// so something is to need normal method, karatsuba algorithm
// and adding two numbers

#include <bits/stdc++.h>
using namespace std;

struct LongLong {
	vector<int> v;

	LongLong(string &s) {
		int n = s.size();
		for (int i = n - 1; i >= 0; i--)
			v.push_back(s[i] - '0');
	}

	LongLong(int d) {
		v.push_back(d);
	}

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

void input(vector<int> &va, vector<int> &vb) {
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	for (int i = n - 1; i >= 0; i--)
		va.push_back(a[i] - '0');
	for (int i = m - 1; i >= 0; i--)
		vb.push_back(b[i] - '0');
}

void outputNumber(vector<int> &a) {
	int n = a.size();
	for (int i = n - 1; i >= 0; i--)
		printf("%d", a[i]);
	puts("");
}

void setToSameDigit(vector<int> &a, vector<int> &b) {
	if (a.size() < b.size())
		swap(a, b);
	// we assume that the size of a is always larger than b.
	int n = a.size() - b.size();
	for (int i = 0; i < n; i++)
		b.push_back(0);
}


int main() {
	string sa, sb;
	cin >> sa >> sb;

	LongLong a(sa);
	LongLong b(sb);

	LongLong c = a + b;

	
	c.print();

	return 0;
}