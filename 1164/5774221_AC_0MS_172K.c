#include <stdio.h>
#include <string.h>
#define MAXN 102
char map[MAXN][MAXN];
int mask[4] = {1, 2, 4, 8};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int cnt, max, tot, n, m;
void init()
{
	int x, y, i, j, k, p;
	scanf("%d %d", &n, &m);
	memset(map, '#', sizeof(map));
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			scanf("%d", &p);
			x = i << 1;
			y = j << 1;
			map[x][y] = ' ';
			for(k = 0;k < 4; k++)
				if((p & mask[k]) == 0) map[x + dx[k]][y + dy[k]] = ' ';
		}
	}
	n <<= 1; n++;
	m <<= 1; m++;
}
void dfs(int x, int y)
{
	int tx, ty, i;
	map[x][y] = '*';
	if(x % 2 == 0 && y % 2 == 0) cnt++;
	for(i = 0;i < 4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
		if(map[tx][ty] != ' ') continue;
		dfs(tx, ty);
	}
}
void solve()
{
	int i, j;
	tot = 0;
	max = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			if(map[i][j] == ' ')
			{
				tot++;
				cnt = 0;
				dfs(i, j);
				if(max < cnt) max = cnt;
			}
		}
	}
	printf("%d\n", tot);
	printf("%d\n", max);
}
int main()
{
	init();
	solve();
	return 0;
}
