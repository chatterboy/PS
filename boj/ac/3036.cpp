// AC
#include <cstdio>
#include <iostream>
using namespace std;

int n, a[100];

struct _frac
{
	int b, a;
	_frac() : b(0), a(0) {}
	_frac(int _b, int _a)
	{
		b = _b; a = _a;
		int g = gcd(b, a);
		b /= g; a /= g;
	}
	int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a % b);
	}
};

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

	_frac l(1, 1);
	for (int i=1; i<n; ++i)
	{
		_frac p(a[i-1]*l.b, a[i]*l.a);
		printf("%d/%d\n", p.b, p.a);
		l.b = p.b; l.a = p.a;
	}
}