#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXN 102
int adj[MAXN][MAXN];
int ancestor[MAXN];
int color[MAXN];
int deep[MAXN];
int cut[MAXN];
int root, n;
void dfs(int k, int pre, int dp)
{
	int tot, i;
	color[k] = 1;
	deep[k] = dp;
	ancestor[k] = dp;
	tot = 0;
	for(i = 1;i <= n; i++)
	{
		if(adj[k][i] && i != pre && color[i] == 1)
			ancestor[k] = MIN(ancestor[k], deep[i]);
		if(adj[k][i] && color[i] == 0)
		{
			dfs(i, k, dp + 1);
			tot++;
			ancestor[k] = MIN(ancestor[k], ancestor[i]);
			if((k == root && tot > 1) || 
				(k != root && ancestor[i] >= deep[k])) cut[k] = 1;
		}
	}
	color[k] = 2;
}
int init()
{
	char ch;
	int i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
	memset(adj, 0, sizeof(adj));
	while(1)
	{
		scanf("%d", &i);
		if(i == 0) break;
		while(1)
		{
			ch = getchar();
			if(ch == '\n') break;
			scanf("%d", &j);
			adj[i][j] = 1;
			adj[j][i] = 1;
		}
	}
	return 1;
}
int main()
{
	int cnt, i;
	while(init())
	{
		memset(color, 0, sizeof(color));
		memset(cut, 0, sizeof(cut));
		root = 1; cnt = 0;
		dfs(root, root, 1);
		for(i = 1;i <= n; i++) cnt += cut[i];
		printf("%d\n", cnt);
	}
	return 0;
}
