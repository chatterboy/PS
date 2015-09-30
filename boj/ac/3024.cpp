// AC
#include <cstdio>
#include <cctype>
#include <set>
using namespace std;
int n;
char bd[30][31];
bool iswinner(char player)
{
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
		{
			if (i+3 <= n)
			{
				bool down = true;
				for (int ii=i; ii<i+3; ++ii)
					down &= bd[ii][j] == player;
				if (down) return true;
			}
			if (i+3 <= n && j+3 <= n)
			{
				bool rd = true;
				for (int t=0; t<3; ++t)
					rd &= bd[i+t][j+t] == player;
				if (rd) return true;
			}
			if (i+3 <= n && j-3 >= -1)
			{
				bool ld = true;
				for (int t=0; t<3; ++t)
					ld &= bd[i+t][j-t] == player;
				if (ld) return true;
			}
		}
	return false;
}
int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%s", bd[i]);

	set<char> players;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (isupper(bd[i][j]))
				players.insert(bd[i][j]);

	bool found = false;
	for (auto player : players)
	{
		if (iswinner(player))
		{
			putchar(player);
			found = true;
			break;
		}
	}

	if (!found) printf("ongoing");
}