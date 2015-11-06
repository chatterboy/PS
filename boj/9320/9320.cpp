#include <cstdio>
int num[4], op[3];
bool found;
int goohaja(int l, int r)
{
	if (l == r) return num[l];
	int ret;
	for (int k = l; k < r; k++)
	{
		if (op[k] == 0)
			ret = goohaja(l, k) + goohaja(k+1, r);
		if (op[k] == 1)
			ret = goohaja(l, k) - goohaja(k+1, r);
		if (op[k] == 2)
			ret = goohaja(l, k) * goohaja(k+1, r);
		if (op[k] == 3)
			ret = goohaja(l, k) / goohaja(k+1, r);
	}
	
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int num[4];
		for (int i = 0; i < 4; i++)
			scanf("%d", &num[i]);
		bool found = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
				{
					int op[3] = {i, j, k};
					if (goohaja(0, 3))
						found = true;
				}
		puts(found ? "YES" : "NO");
	}
}