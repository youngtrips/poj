#include <stdio.h>
#define MAXN 102
int n, max;
int path[MAXN][MAXN];
int inClique[MAXN];
int ans[MAXN];
void dfs(int inGraph[])
{
	int i, j;
	int Graph[MAXN];
	if(inClique[0] + inGraph[0] <= max ) return;
	if(inClique[0] > max)
	{
		max = inClique[0];
		for(i = 1;i <= max; i++) ans[i] = inClique[i];
	}
	for(i = 1;i <= inGraph[0]; i++)
    {
		++inClique[0];
		inClique[inClique[0]] = inGraph[i];
		Graph[0] = 0;
		for(j = i + 1;j <= inGraph[0]; j++)
			if(path[inGraph[i]][inGraph[j]] ) Graph[++Graph[0]] = inGraph[j];
		dfs(Graph);
		--inClique[0];
	}
}
int main()
{
	int inGraph[MAXN];
	int i, j, t, k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		for(i = 1;i <= n; i++)
		{
			for(j = 1;j <= n; j++) path[i][j] = 1;
			path[i][i] = 0;
		}
		while(k--)
		{
			scanf("%d %d", &i, &j);
			path[i][j] = 0;
			path[j][i] = 0;
		}
		max = 1;
        inClique[0]= 0;
        inGraph[0] = n;
		for(i = 0;i < n; i++) inGraph[i + 1] = i;
        dfs(inGraph);
		printf("%d\n", max);
		printf("%d", ans[1]);
		for(i = 2;i <= max; i++) printf(" %d",  ans[i]);
		printf("\n");
	}
	return 0;
}
