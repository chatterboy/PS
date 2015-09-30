#include <cstdio>
#include <algorithm>
using namespace std;

int n, mat[20][20];
double dp[1<<20];

double solve(int pos, int vst)
{
	if ((((1<<n)-1)&vst) == (1<<n)-1) return 1.;
	double &ret = dp[vst];
	if (ret != -1.) return ret;
	ret = .0;
	for (int i=0; i<n; i++)
		if ((vst&(1<<i))==0)
			ret = max(ret, solve(pos+1, vst|(1<<i)) *(1.*mat[pos][i]/100.));
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) scanf("%d", &mat[i][j]);

	for (int i=0; i<(1<<n); ++i) dp[i] = -1.;

	printf("%lf", solve(0, 0)*100.);
}
