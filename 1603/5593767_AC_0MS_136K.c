#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXN 22
int adj[MAXN][MAXN];
void floyd()
{
	int i, j, k;
	for(k = 1;k <= 20; k++)
		for(i = 1;i <= 20; i++)
			for(j = 1;j <= 20; j++)
				if(adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];
}
int init()
{
	int i, j, k;
	for(i = 1;i <= 20; i++)
		for(j = 1;j <= 20; j++) adj[i][j] = (i == j ? 0 : oo);
	for(i = 1;i <= 19; i++)
	{
		if(scanf("%d", &k) == EOF) return 0;
		while(k--)
		{
			scanf("%d", &j);
			adj[i][j] = 1;
			adj[j][i] = 1;
		}
	}
	return 1;
}
int main()
{
	int n, i, j, s = 1;
	while(init())
	{
		floyd();
		scanf("%d", &n);
		printf("Test Set #%d\n", s++);
		while(n--)
		{
			scanf("%d %d", &i, &j);
			printf("%d to %d: %d\n", i, j, adj[i][j]);
		}
		printf("\n");
	}
	return 0;
}
