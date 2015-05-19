#include <stdio.h>
#define MAXM 100002
#define MAXN 1002
#define oo 123456789
typedef struct
{
	int u;
	int v;
	int w;
}Edge;
Edge e[MAXM], re[MAXM];
int tot, st, n;
int d[MAXN], r[MAXN];
void init()
{
	int m, i;
	scanf("%d %d %d", &n, &m, &st);
	tot = 0;
	while(m--)
	{
		scanf("%d %d %d", &e[tot].u, &e[tot].v, &e[tot].w);
		re[tot].v = e[tot].u;
		re[tot].u = e[tot].v;
		re[tot].w = e[tot].w;
		tot++;
	}
}
void bellman_ford(Edge* e)
{
	int k, i, f;
	for(i = 1;i <= n; i++) d[i] = oo;
	d[st] = 0;
	f = 1;
	for(k = 1;k < n; k++)
	{
		for(i = 0;i < tot; i++)
			if(d[e[i].u] < oo && d[e[i].v] > d[e[i].u] + e[i].w) {d[e[i].v] = d[e[i].u] + e[i].w; f = 0;}
		if(f) break;
	}
}
int main()
{
	long long ans = 0;
	int i;
	init();
	bellman_ford(e);
	for(i = 1;i <= n; i++) r[i] = d[i];
	bellman_ford(re);
	for(i = 1;i <= n; i++)
	{
		r[i] += d[i];
		if(ans < r[i]) ans = r[i];
	}
	printf("%d\n", ans);
	return 0;
}
