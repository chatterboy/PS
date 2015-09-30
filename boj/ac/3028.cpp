// AC
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	char str[51];
	scanf("%s", str);
	int cup[]={1,0,0};
	for (char *pch=str; *pch; ++pch)
	{
		if (*pch == 'A')
		{
			swap(cup[0], cup[1]);
		}
		else if (*pch == 'B')
		{
			swap(cup[1], cup[2]);
		}
		else
		{
			swap(cup[0], cup[2]);
		}
	}
	for (int i=0; i<3; ++i)
		if (cup[i]) printf("%d", i+1);
}