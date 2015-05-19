#include <stdio.h>
#define oo 999999999
#define MAX 302
int adj[MAX][MAX], n;
int max(int x, int y) { return x > y ? x : y;}
void floyd()
{
	int i, j, k;
	for(k = 1;k <= n; k++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++)
				if(adj[i][j] > adj[i][k] && adj[i][j] > adj[k][j])
					adj[i][j] = max(adj[i][k], adj[k][j]);
}
int main()
{
	int m, t, i, j, c;
	scanf("%d %d %d", &n, &m, &t);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) adj[i][j] = (i == j ? 0 : oo);
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &c);
		adj[i][j] = c;
	}
	floyd();
	while(t--)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", adj[i][j] == oo ? -1 : adj[i][j]);
	}
	return 0;
}
