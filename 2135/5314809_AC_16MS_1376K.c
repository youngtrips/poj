#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 10002
#define MAXN 1002
typedef struct {int u; int v; int f; int c; int op; int next;}edge_t;
edge_t e[MAXM * 4];
int q[MAXN], pre[MAXN], d[MAXN], head, tail;
int first[MAXN], tot, n;
void add(int u, int v, int f, int c)
{
	e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].c = c;
	e[tot].op = tot + 1; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].c = -c;
	e[tot].op = tot - 1; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int i, j, k, m;
	memset(first, -1, sizeof(first));
	scanf("%d %d", &n, &m);
	tot = 0;
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &k);
		add(i, j, 1, k);
		add(j, i, 1, k);
	}
	add(0, 1, 2, 0);
	add(n, n + 1, 2, 0);
	n++;
}
int bellman_ford()
{
	int flag, i, j, t;
	memset(pre, -1, sizeof(pre));
	for(i = 0;i <= n; i++) d[i] = oo;
	d[0] = 0;
	while(1)
	{
		flag = 1;
		for(i = 0;i <= n; i++)
		{
			if(d[i] == oo) continue;
			t = first[i];
			while(t != -1)
			{
				j = e[t].v;
				if(e[t].f > 0 && d[j] > d[i] + e[t].c)
				{
					pre[j] = t;
					flag = 0;
					d[j] = d[i] + e[t].c;
				}
				t = e[t].next;
			}
		}
		if(flag) break;
	}
	return d[n] != oo;
}
int min_cost_flow()
{
	int min = 0, i, j, t;
	while(bellman_ford())
	{
		min += d[n];
		i = n;
		while(pre[i] != -1)
		{
			t = pre[i];
			e[t].f--;
			e[e[t].op].f++;
			e[e[t].op].c = -e[t].c;
			i = e[t].u;
		}
	}
	return min;
}
int main()
{
	int res;
	init();
	res = min_cost_flow();
	printf("%d\n", res);
	return 0;
}
