//AC
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, m, water[52][52], d[]={0,0,-1,1};
char bd[52][52];
queue<pair<int, int>> q;
queue<pair<pair<int, int>, int>> qq;
bool vst[52][52];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) scanf("%s", bd[i]);

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j) water[i][j] = 987654321;

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (bd[i][j] == '*')
			{
				water[i][j] = 0;
				q.push(make_pair(i, j));
			}

	while (!q.empty())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();
		for (int i=0; i<4; ++i)
		{
			int ny = cy + d[i], nx = cx + d[(i+2)%4];
			if ((0<=ny && ny<n) && (0<=nx && nx<m))
			{
				if (water[ny][nx] == 987654321 && bd[ny][nx] != 'X' && bd[ny][nx] != 'D' && water[ny][nx] > water[cy][cx] + 1)
				{
					water[ny][nx] = water[cy][cx] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (bd[i][j] == 'S')
			{
				vst[i][j] = true;
				qq.push(make_pair(make_pair(i, j), 0));
				while (!qq.empty())
				{
					int cy = qq.front().first.first, cx = qq.front().first.second;
					int cd = qq.front().second;
					qq.pop();
					if (bd[cy][cx] == 'D')
					{
						printf("%d", cd);
						exit(0);
					}
					for (int i=0; i<4; ++i)
					{
						int ny = cy + d[i], nx = cx + d[(i+2)%4];
						if ((0<=ny && ny<n) && (0<=nx && nx<m))
						{
							if (bd[ny][nx] != 'X' && (water[ny][nx] == 'D' || cd+1 < water[ny][nx]) && (!vst[ny][nx]))
							{
								vst[ny][nx] = true;
								qq.push(make_pair(make_pair(ny, nx), cd+1));
							}
						}
					}
				}
			}	

	puts("KAKTUS");
}