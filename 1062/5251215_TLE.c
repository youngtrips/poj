#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAX 102
int adj[MAX][MAX], price[MAX], level[MAX], flag[MAX], d[MAX], m, n;
int Abs(int x) { return x < 0 ? -x : x;}
void init()
{
	int i, j, c, x;
	scanf("%d %d", &m, &n);
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d %d", &price[i], &level[i], &x);
		while(x--)
		{
			scanf("%d %d", &j, &c);
			adj[i][j] = c;
			adj[j][i] = c;
		}
	}
	for(i = 1;i <= n; i++) d[i] = oo;
}
void bellman_ford()
{
	int i, j, k;
	d[1] = 0;
	for(k = 1;k < n; k++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++) 
				if(d[i] < oo && adj[i][j] && d[j] > d[i] + adj[i][j]) d[j] = d[i] + adj[i][j];
}
void dfs(int st, int max)
{
	int i;
	for(i = 1;i <= n; i++)
	{
		if(adj[st][i] && flag[i] == 0)
		{
			if(Abs(max - level[i]) > m)
			{
				adj[st][i] = 0;
				adj[i][st] = 0;
			}
			else
			{
				if(max < level[i]) max = level[i];
				flag[i] = 1;
				dfs(i, max);
				flag[i] = 0;
			}
		}
	}
}
int main()
{
	int ans, i;
	init();
	memset(flag, 0, sizeof(flag));
	flag[1] = 1;
	dfs(1, level[1]);
	bellman_ford();
	ans = oo;
	for(i = 2;i <= n; i++)
		if(ans > d[i] + price[i]) ans = d[i] + price[i];
	if(ans == oo) ans = price[1];
	printf("%d\n", ans);
	return 0;
}
