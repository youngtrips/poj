#include <stdio.h>
#include <string.h>
#define MAX 102
int adj[MAX][MAX], n;
void init()
{
	int m, i, j;
	scanf("%d %d", &n, &m);
	memset(adj, 0, sizeof(adj));
	while(m--)
	{
		scanf("%d %d", &i, &j);
		adj[i][j] = 1;
	}
}
void cup()
{
	int i, j, k;
	for(k = 1;k <= n; k++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++)
				adj[i][j] |= (adj[i][k] & adj[k][j]);
}
int main()
{
	int cnt, deg, i, j;
	init();
	cup();
	cnt = 0;
	for(i = 1;i <= n; i++)
	{
		deg = 0;
		for(j = 1;j <= n; j++) deg += adj[i][j] + adj[j][i];
		if(deg == n - 1) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
