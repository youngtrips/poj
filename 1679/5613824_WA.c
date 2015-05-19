#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXN 102
int adj[MAXN][MAXN];
int has[MAXN];
int key[MAXN];
int n;
int prim()
{
	int res, min,i, j, k, p;
	for(i = 1;i <= n; i++)
	{
		key[i] = adj[1][i];
		has[i] = 0;
	}
	has[1] = 1; res = 0;
	for(i = 1;i < n; i++)
	{
		min = oo;
		k = 1;
		for(j = 1;j <= n; j++)
		{
			if(has[j] == 0 && min > key[j])
			{
				min = key[j];
				k = j;
			}
		}
		has[k] = 1;
		res += min;
		for(p = 1;p <= n; p++)
			for(j = p + 1;j <= n; j++)
				if(has[p] == 1 && has[j] == 0 && adj[p][j] == min) return -1;
		for(j = 1;j <= n; j++) if(key[j] > adj[k][j]) key[j] = adj[k][j];
	}
	return res;
}
void init()
{
	int m, i, j, k;
	scanf("%d %d", &n, &m);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) adj[i][j] = (i == j ? 0 : oo);
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &k);
		adj[i][j] = k;
		adj[j][i] = k;
	}
}
int main()
{
	int res;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		res = prim();
		if(res == -1) printf("Not Unique!\n");
		else printf("%d\n", res);
	}
	return 0;
}
