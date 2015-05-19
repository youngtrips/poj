#include <stdio.h>
#define oo 999999999
#define MAXM 5002
#define MAXN 102
typedef struct
{
	int u;
	int v;
	int w;
}edge_t;
edge_t e[MAXM];
int d[MAXN], tot, st, ed, n;
void init()
{
	int i, j, k, m;
	scanf("%d %d %d", &n, &st, &ed);
	tot = 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &m);
		for(k = 0;k < m; k++)
		{
			scanf("%d", &j);
			e[tot].u = i;
			e[tot].v = j;
			e[tot].w = (k == 0 ? 0 : 1);
			tot++;
		}
	}
}
void bellman_ford()
{
	int f, i, k;
	for(i = 1;i <= n; i++) d[i] = oo;
	d[st] = 0;
	for(k = 1;k < n; k++)
	{
		f = 1;
		for(i = 0;i < tot; i++)
		{
			if(d[e[i].u] < oo && d[e[i].v] > d[e[i].u] + e[i].w)
			{
				d[e[i].v] = d[e[i].u] + e[i].w;
				f = 0;
			}
		}
		if(f) break;
	}
}
int main()
{
	int i;
	init();
	bellman_ford();
	printf("%d\n", d[ed] == oo ? -1 : d[ed]);
	return 0;
}
