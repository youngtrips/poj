#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 2002
#define MAXN 1002
typedef struct
{
	int u;
	int v;
	int w;
}edge_t;
edge_t e[MAXM];
int d[MAXN], tot, n;
void init()
{
	int t, u, v, w;
	scanf("%d %d", &t, &n);
	for(tot = 0;tot < t; tot++) scanf("%d %d %d", &e[tot].u, &e[tot].v, &e[tot].w);
	for(t = 1;t <= n; t++) d[t] = oo;
	d[n] = 0;
}
void bellman_ford()
{
	int f, i, k;
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
			if(d[e[i].v] < oo && d[e[i].u] > d[e[i].v] + e[i].w)
			{
				d[e[i].u] = d[e[i].v] + e[i].w;
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
	printf("%d\n", d[1]);
	return 0;
}
