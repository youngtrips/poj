#include <stdio.h>
#include <string.h>
#define MAX 2002
#define black	0
#define red		1
int adj[MAX][MAX];
int color[MAX], flag, n;
void init()
{
	int i, m, u, v;
	scanf("%d %d", &n, &m);
	memset(adj, 0, sizeof(adj));
	memset(color, -1, sizeof(color));
	flag = 0;
	while(m--)
	{
		scanf("%d %d", &u, &v);
		if(u == v) flag = 1;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
}
void dfs(int st, int col)
{
	int i, k = 1;
	color[st] = col;
	k ^= col;
	for(i = 1;i <= n; i++)
	{
		if(adj[st][i])
		{
			if(color[i] == col) {flag = 1; break;;}
			if(color[i] == -1) dfs(i, k);
		}
	}
}
int main()
{
	int s, t, i;
	scanf("%d", &t);
	for(s = 1;s <= t; s++)
	{
		init();
		for(i = 1;i <= n; i++)
		{
			if(flag == 1) break;
			if(color[i] == -1) dfs(i, 0);
		}
		printf("Scenario #%d:\n", s);
		if(flag == 1) printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
}
