#include <stdio.h>
#include <string.h>
#define MAXM 100002
#define MAXN 1002
#define oo 999999999
typedef struct
{
	int u; int v; int w;
}edge_t;
edge_t e[MAXM * 10];
int d[MAXN];
int tot;
int st, n;
void add(int u, int v, int w)
{
	e[++tot].u = u; e[tot].v = v; e[tot].w = w;
}
int init()
{
	char ch[2];
	int i, a, b, x, m;
	if(scanf("%d %d", &n, &m) == EOF) return 0;
	tot = 0; st = oo;
	while(m--)
	{
		scanf("%s", ch);
		if(ch[0] == 'P')
		{
			scanf("%d %d %d", &a, &b, &x);
			if(st > a) st = a;
			if(st > b) st = b;
			add(b, a, x);
			add(a, b, -x);
		}
		else
		{
			scanf("%d %d", &a, &b);
			if(st > a) st = a;
			if(st > b) st = b;
			add(a, b, -1);
		}
	}
	return 1;
}
void bellman_ford()
{
	int flag, ans, i, k;
	for(i = 1;i <= n; i++) d[i] = oo;
	d[st] = 0;
	ans = 0;
	for(k = 1;k < n; k++)
	{
		for(i = 1;i <= tot; i++)
		{
			if(d[e[i].u] != oo && d[e[i].v] > d[e[i].u] + e[i].w)
			{
				d[e[i].v] = d[e[i].u] + e[i].w;
				flag = 0;
			}
		}
		for(i = 1;i <= tot; i++)
		{
			if(d[e[i].v] > d[e[i].u] + e[i].w)
			{
				ans = 1;
				break;
			}
		}
		if(ans) break;
	}
	printf("%s\n", ans == 1 ? "Unreliable" : "Reliable");
}
int main()
{
	while(init())
	{
		bellman_ford();
	}
	return 0;
}
