// AC
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rect
{
	double x1, y1, x2, y2;
	Rect(double _x1, double _y1, double _x2, double _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

int N;
vector<double> X, Y;
vector<Rect> rects;

int main()
{
	cin >> N;
	for (int i=0; i<N; ++i)
	{
		double x, y, w, h;
		cin >> x >> y >> w >> h;
		X.push_back(x); X.push_back(x+w);
		Y.push_back(y); Y.push_back(y+h);
		rects.push_back(Rect(x, y, x+w, y+h));
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());

	double ans = .0;

	for (int i=1; i<X.size(); ++i)
		for (int j=1; j<Y.size(); ++j)
			for (int k=0; k<N; ++k)
				if (X[i-1] >= rects[k].x1 && X[i] <= rects[k].x2 && Y[j-1] >= rects[k].y1 && Y[j] <= rects[k].y2)
				{
					ans += (X[i]-X[i-1]) * (Y[j]-Y[j-1]);
					break;
				}

	if (ans-(long long)ans < 1e-3) printf("%lld", (long long)ans);
	else printf("%.2lf", ans);
}