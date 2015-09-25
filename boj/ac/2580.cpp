#include <iostream>
#include <vector>
using namespace std;
int bd[9][9], isNumRow[10][10], isNumCol[10][10], isNumRect[10][10];
vector<int> sx, sy;
int where(int y, int x)
{
	int here = 0;
	for (int i=0; i<9; i+=3)
		for (int j=0; j<9; j+=3, here++)
			if ((i<=y && y<i+3) && (j<=x && x<j+3))
				return here;
}
bool can(int pos)
{
	if (isNumRow[sy[pos]][bd[sy[pos]][sx[pos]]] > 1)
		return false;
	if (isNumCol[sx[pos]][bd[sy[pos]][sx[pos]]] > 1)
		return false;
	if (isNumRect[where(sy[pos], sx[pos])][bd[sy[pos]][sx[pos]]] > 1)
		return false;
	return true;
}
bool solve(int pos)
{
	if (pos == sx.size())
		return true;
	for (int num=1; num<10; ++num)
	{
		bd[sy[pos]][sx[pos]] = num;
		isNumRow[sy[pos]][num]++;
		isNumCol[sx[pos]][num]++;
		isNumRect[where(sy[pos], sx[pos])][num]++;
		if (can(pos))
			if (solve(pos+1))
				return true;	
		isNumRow[sy[pos]][num]--;
		isNumCol[sx[pos]][num]--;
		isNumRect[where(sy[pos], sx[pos])][num]--;			
		bd[sy[pos]][sx[pos]] = 0;
	}
	return false;
}
int main()
{
	for (int i=0; i<9; ++i)
		for (int j=0; j<9; ++j)
			cin >> bd[i][j];

	for (int i=0; i<9; ++i)
		for (int j=0; j<9; ++j)
			if (bd[i][j] == 0)
			{
				sy.push_back(i);
				sx.push_back(j);
			}

	for (int i=0; i<9; ++i)
		for (int j=0; j<9; ++j)
		{
			isNumRow[i][bd[i][j]]++;
			isNumCol[j][bd[i][j]]++;
			isNumRect[where(i, j)][bd[i][j]]++;
		}

	solve(0);

	for (int i=0; i<9; ++i)
	{
		for (int j=0; j<8; ++j)
			printf("%d ", bd[i][j]);
		printf("%d\n", bd[i][8]);
	}
}