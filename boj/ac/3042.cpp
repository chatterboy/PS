// AC
#include <cstdio>
#include <vector>
using namespace std;

int n;
char bd[102][102];
vector<int> x, y;

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%s", bd[i]);

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (bd[i][j] != '.')
			{
				y.push_back(i);
				x.push_back(j);
			}

	int ans = 0;
	int m = x.size();

	for (int i=0; i<m; ++i)
		for (int j=i+1; j<m; ++j)
			for (int k=j+1; k<m; ++k)
				if ((x[k]-x[i])*(y[j]-y[i]) == (x[j]-x[i])*(y[k]-y[i]))
					ans++;

	printf("%d", ans);
}