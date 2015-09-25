#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define maxxy 1002
#define maxl 102
#define maxw 102
#define inf 987654321

int x, y, t, l, w, xleak[maxl], yleak[maxl];
int x1wall[maxw], y1wall[maxw], x2wall[maxw], y2wall[maxw];
int floor[maxxy][maxxy], d[]={0,0,-1,1};
queue<pair<int, int> > q;

void init()
{
	q = queue<pair<int, int> >();
	for (int i=1; i<=y; ++i)
		for (int j=1; j<=x; ++j) floor[i][j] = inf;
}

void makeWall()
{
	for (int i=0; i<w; ++i)
	{
		int x1=x1wall[i], y1=y1wall[i], x2=x2wall[i], y2=y2wall[i];
		if (y1 < y2)
		{
			if (x1 < x2)
			{
				for (int t=0; y1+t<=y2; ++t)
					floor[y1+t][x1+t] = -1;
			}
			else if (x1 == x2)
			{
				for (int t=0; y1+t<=y2; ++t)
					floor[y1+t][x1] = -1;
			}
			else
			{
				for (int t=0; y1+t<=y2; ++t)
					floor[y1+t][x1-t] = -1;
			}
		}
		else if (y1 == y2)
		{
			if (x1 < x2)
			{
				for (int jj=x1; jj<=x2; ++jj)
					floor[y1][jj] = -1;
			}
			else
			{
				for (int jj=x2; jj<=x1; ++jj)
					floor[y1][jj] = -1;
			}
		}
		else
		{
			if (x1 < x2)
			{
				for (int t=0; y1-t>=y2; ++t)
					floor[y1-t][x1+t] = -1;
			}
			else if (x1 == x2)
			{
				for (int t=0; y1-t>=y2; ++t)
					floor[y1-t][x1] = -1;
			}
			else
			{
				for (int t=0; y1-t>=y2; ++t)
					floor[y1-t][x1-t] = -1;
			}
		}
	}
}

int main()
{
	while (1)
	{
		cin >> x;
		if (x == -1) break;
		cin >> y >> t >> l >> w;
		for (int i=0; i<l; ++i) cin >> xleak[i] >> yleak[i];
		for (int i=0; i<w; ++i)
			cin >> x1wall[i] >> y1wall[i] >> x2wall[i] >> y2wall[i];
		init();
		makeWall();
		for (int i=0; i<l; ++i)
		{
			floor[yleak[i]][xleak[i]] = 1;
			q.push(make_pair(xleak[i], yleak[i]));
		}
		while (!q.empty())
		{
			int cx = q.front().first, cy = q.front().second;
			q.pop();
			for (int i=0; i<4; ++i)
			{
				int nx = cx+d[i], ny = cy+d[(i+2)%4];
				if (nx<1 || ny<1 || nx>x || ny>y) continue;
				if (floor[ny][nx] == inf && floor[ny][nx] > floor[cy][cx] && floor[cy][cx] < t)
				{
					floor[ny][nx] = floor[cy][cx] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		int ans = 0;
		for (int i=1; i<=y; ++i)
			for (int j=1; j<=x; ++j)
				if (1<=floor[i][j] && floor[i][j]<inf) ans++;
		printf("%d\n", ans);
	}
}