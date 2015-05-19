#include <stdio.h>
#include <string.h>
#define ALL 0x1FF
#define MAXN 10
int mask[10] = { 0, 256, 128, 64, 32, 16, 8, 4, 2, 1};
int grid[MAXN][MAXN];
int g_no[MAXN][MAXN];
int pos[MAXN * MAXN][2];
int row[MAXN];
int col[MAXN];
int sub[MAXN];
int found;
int tot;
void init()
{
	int i, j, k;
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	tot = 0;
	for(i = 1;i <= 9; i++)
	{
		for(j = 1;j <= 9; j++)
		{
			k = getchar() - '0';
			grid[i][j] = k;
			row[i] |= mask[k];
			col[j] |= mask[k];
			if(k == 0)
			{
				pos[++tot][0] = i;
				pos[tot][1] = j;
			}
		}
		getchar();
	}
}
void preprocess()
{
	int ii, jj, x, y, i, j, k;
	memset(g_no, 0, sizeof(g_no));
	memset(sub, 0, sizeof(sub));
	k = 0;
	for(i = 1;i <= 3; i++)
	{
		for(j = 1;j <= 3; j++)
		{
			++k;
			for(ii = 1;ii <= 3; ii++)
			{
				x = (i - 1) * 3 + ii;
				for(jj = 1;jj <= 3; jj++)
				{
					y = (j - 1) * 3 + jj;
					g_no[x][y] = k;
					sub[k] |= mask[grid[x][y]];
				}
			}
		}
	}
}
int check(int x, int y, int k)
{
	int a = ALL ^ (row[x] | col[y] | sub[g_no[x][y]]);
	a = (a>>(9 - k)) & 1;
	return a;
}
void set_mark(int x, int y, int k)
{
	row[x] |= mask[k];
	col[y] |= mask[k];
	sub[g_no[x][y]] |= mask[k];
}
void unset_mark(int x, int y, int k)
{
	row[x] ^= mask[k];
	col[y] ^= mask[k];
	sub[g_no[x][y]] ^= mask[k];
}
void output()
{
	int i, j;
	for(i = 1;i <= 9; i++)
	{
		for(j = 1;j <= 9; j++) printf("%d", grid[i][j]);
		printf("\n");
	}
}
int is_ok()
{
	int i;
	for(i = 1;i <= 9; i++) if(col[i] != ALL || sub[i] != ALL || row[i] != ALL) return 0;
	return 1;
}
void dfs(int i)
{
	int j, x, y;
	if(found) return;
	if(i == 0)
	{
		if(is_ok())
		{
			output();
			found = 1;
		}
		return;
	}
	x = pos[i][0]; y = pos[i][1];
	for(j = 1;j <= 9; j++)
	{
		if(check(x, y, j))
		{
			grid[x][y] = j;
			set_mark(x, y, j);
			dfs(i-1);
			grid[x][y] = 0;
			unset_mark(x, y, j);
		}
	}
}
int main()
{
	int c = 1;
	int t;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		init();
		preprocess();
		found = 0;
		dfs(tot);
	}
	return 0;
}
