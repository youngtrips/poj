#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAX 102
int adj[MAX][MAX], price[MAX], level[MAX], d[MAX], m, n;
int Abs(int x) { return x < 0 ? -x : x;}
void init()
{
	int max, i, j, c, x;
	scanf("%d %d", &m, &n);
	memset(adj, 0, sizeof(adj));
	max = 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d %d", &price[i], &level[i], &x);
		if(max < level[i]) max = level[i];
		while(x--)
		{
			scanf("%d %d", &j, &c);
			adj[i][j] = c;
			adj[j][i] = c;
		}
	}
	for(i = 1;i <= n; i++)
	{
		d[i] = oo;
		for(j = 1;j <= n; j++)
			if(adj[i][j] && Abs(level[i] - level[j]) > m) adj[i][j] = adj[j][i] = 0;
	}
	max -= m;
	for(i = 1;i <= n; i++)
	{
		if(level[i] < max)
			for(j = 1;j <= n; j++) {adj[i][j] = 0; adj[j][i] = 0;}
	}
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
int main()
{
	int ans, i;
	init();
	bellman_ford();
	ans = oo;
	for(i = 2;i <= n; i++)
		if(ans > d[i] + price[i]) ans = d[i] + price[i];
	if(ans == oo) ans = price[1];
	printf("%d\n", ans);
	return 0;
}
