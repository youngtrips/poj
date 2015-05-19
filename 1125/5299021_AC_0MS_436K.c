#include <stdio.h>
#define oo 999999999
#define MAX 102
int adj[MAX][MAX], n;
void floyd()
{
	int i, j, k;
	for(k = 1;k <= n; k++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++)
				if(adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];
}
int init()
{
	int i, j, k, m;
	scanf("%d", &n);
	if(n == 0) return 0;
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) adj[i][j] = (i == j ? 0 : oo);
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d %d", &j, &k);
			adj[i][j] = k;
		}
	}
	return 1;
}
int main()
{
	int disjoin, flag, max, min, p, i, j;
	while(init())
	{
		floyd();
		min = oo;
		disjoin = 1;
		for(i = 1;i <= n; i++)
		{
			flag = 0;
			max = 0;
			for(j = 1;j <= n; j++)
			{
				if(max < adj[i][j]) max = adj[i][j];
				if(adj[i][j] == oo) flag = 1;
			}
			if(min > max) { min = max; p = i;}
			disjoin &= flag;
		}
		if(disjoin) printf("disjoint\n");
		else printf("%d %d\n", p, min);
	}
	return 0;
}
