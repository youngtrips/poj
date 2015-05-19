#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXN 102
char has[MAXN];
int adj[MAXN][MAXN];
int n;
int prim()
{
	int res, min, tmp, i, j, k, p;
	memset(has, 0, sizeof(has));
	has[1] = 1; res = 0;
	for(i = 1;i <= n; i++)
	{
		min = oo; tmp = oo - 1;
		for(j = 1;j <= n; j++)
		{
			if(has[j] == 0) continue;
			for(k = 1;k <= n; k++)
			{
				if(has[k] == 0 && adj[j][k] > -oo)
				{
					if(min >= adj[j][k])
					{
						tmp = min;
						min = adj[j][k];
						p = k;
					}
				}
			}
		}
		if(min == tmp) return -1;
		if(min != oo)
		{
			res += min;
			has[p] = 1;
		}
	}
	return res;
}
void init()
{
	int m, i, j, k;
	scanf("%d %d", &n, &m);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) adj[i][j] = (i == j ? 0 : -oo);
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &k);
		adj[i][j] = k;
		adj[j][i] = k;
	}
}
int main()
{
	int res, t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		res = prim();
		if(res < 0) printf("Not Unique!\n");
		else printf("%d\n", res);
	}
	return 0;
}
