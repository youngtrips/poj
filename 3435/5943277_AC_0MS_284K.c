#include <stdio.h>
#include <string.h>
#define MAXN 102
int grid[MAXN][MAXN];
int g_no[MAXN][MAXN];
int col[MAXN][MAXN];
int row[MAXN][MAXN];
int sub[MAXN][MAXN];

int n;
void gen_no()
{
	int ii, jj, i, j, k, x, y;
	k = -1;
	for(i = 0;i < n; i++)
	{
		for(j = 0;j < n; j++)
		{
			++k;
			for(ii = 0;ii < n; ii++)
			{
				x = i * n + ii;
				for(jj = 0;jj < n; jj++)
				{
					y = j * n + jj;
					g_no[x][y] = k;
				}
			}
		}
	}
}
void solve()
{
	int flag, n2, i, j, k;
	memset(col, 0, sizeof(col));
	memset(row, 0, sizeof(row));
	memset(sub, 0, sizeof(sub));
	flag = 0; n2 = n * n;
	for(i = 0;i < n2; i++)
	{
		for(j = 0;j < n2; j++)
		{
			scanf("%d", &k);
			if(k == 0) continue;
			if(row[i][k] == 0) row[i][k] = 1;
			else flag = 1;
			if(col[j][k] == 0) col[j][k] = 1;
			else flag = 1;
			if(sub[g_no[i][j]][k] == 0) sub[g_no[i][j]][k] = 1;
			else flag = 1;
		}
	}
	printf("%s\n", flag == 1 ? "INCORRECT" : "CORRECT");
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		gen_no();
		solve();
	}
	return 0;
}
