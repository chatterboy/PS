// AC
#include <cstdio>
#include <iostream>
using namespace std;

int r, c, zr, zc;
char src[52][52], des[252][252];

int main()
{
	scanf("%d%d%d%d", &r, &c, &zr, &zc);
	for (int i=0; i<r; ++i) scanf("%s", src[i]);

	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			for (int ii=zr*i; ii<zr*(i+1); ++ii)
				for (int jj=zc*j; jj<zc*(j+1); ++jj)
					des[ii][jj] = src[i][j];

	for (int i=0; i<zr*r; ++i)
	{
		for (int j=0; j<zc*c; ++j) putchar(des[i][j]);
		putchar('\n');
	}
}