#include <stdio.h>
#include <string.h>
#define MAXN 100
int adj[MAXN][MAXN];
int rev[MAXN][MAXN];
int has[MAXN];
int deg[MAXN];
int n;
void init()
{
	int m, i, j;
	scanf("%d %d", &n, &m);
	memset(adj, 0, sizeof(adj));
	memset(rev, 0, sizeof(adj));
	while(m--)
	{
		scanf("%d %d", &i, &j);
		adj[i][j] = 1;
		rev[j][i] = 1;
	}
}
void cup(int mat[][MAXN])
{
	int i, j, k;
	for(k = 1;k <= n; k++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++)
				mat[i][j] |= mat[i][k] & mat[k][j];
}
void solve()
{
	int max, i, j;
	cup(adj);
	cup(rev);
	memset(has, 0, sizeof(has));
	memset(deg, 0, sizeof(deg));
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) deg[i] += adj[i][j];
	for(i = 1;i <= n; i++) if(deg[i] >= n / 2) has[i] = 1;
	memset(deg, 0, sizeof(deg));
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) deg[i] += rev[i][j];
	for(i = 1;i <= n; i++) if(deg[i] >= n / 2) has[i] = 1;
	max = 0;
	for(i = 1;i <= n; i++) max += has[i];
	printf("%d\n", max);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}
