#include <stdio.h>
#define MAXM 2702
#define MAXN 502
#define oo 999999999999999LL
typedef struct
{
	int u;
	int v;
	int w;
}Edge;
Edge e[MAXM];
int cur, n;
long long d[MAXN];
char ans[2][4] = {"NO", "YES"};
void init()
{
	int i, j, x, m, w;
	scanf("%d %d %d", &n, &m, &w);
	cur = 0;
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &x);
		e[cur].u = i;
		e[cur].v = j;
		e[cur].w = x;
		cur++;
	}
	while(w--)
	{
		scanf("%d %d %d", &i, &j, &x);
		e[cur].u = i;
		e[cur].v = j;
		e[cur].w = -x;
		cur++;
	}
}

int bellman_ford()
{
	int f, k, i;
	for(i = 1;i <= n; i++) d[i] = oo;
	d[1] = 0;
	for(k = 1;k < n; k++)
	{
		f = 1;
		for(i = 0;i < cur; i++)
		{
			if(d[e[i].u] < oo && d[e[i].v] > d[e[i].u] + e[i].w)
			{
				d[e[i].v] = d[e[i].u] + e[i].w;
				f = 0;
			}
			if(e[i].w > 0 && d[e[i].v] < oo && d[e[i].u] > d[e[i].v] + e[i].w)
			{
				d[e[i].u] = d[e[i].v] + e[i].w;
				f = 0;
			}
		}
		if(f) break;
	}
	for(i = 0;i < cur; i++)
	{
		if(d[e[i].v] > d[e[i].u] + e[i].w) return 1;
		if(e[i].w > 0 && d[e[i].u] > d[e[i].v] + e[i].w) return 1;
	}
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		printf("%s\n", ans[bellman_ford()]);
	}
	return 0;
}
