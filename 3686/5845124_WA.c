#include <stdio.h>
#include <string.h>
#define oo 99999999999999999ll
#define MAXM 128002
#define MAXN 3008
#define MAXQ 5002
typedef __int64 LL;
typedef struct
{
	int u; int v; int f; int c; int next;
}edge_t;
edge_t e[MAXM * 2];
int first[MAXN];
LL dis[MAXN];
int que[MAXQ];
int has[MAXN];
int pre[MAXN];
int head, tail;
int tot, st, ed;
int n, m;
void add(int u, int v, int f, int c)
{
	e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].c = c; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].c = -c;e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int i, j, k, x;
	scanf("%d %d", &n, &m);
	memset(first, -1, sizeof(first)); tot = -1;
	st = 0; ed = n + m * n + 1;
	for(i = 1;i <= n; i++)
	{
		add(st, i, 1, 0);
		for(j = 1;j <= m; j++)
		{
			scanf("%d", &x);
			for(k = 1;k <= n; k++) add(i, n * j + k, 1, x * k);
		}
	}
	for(i = n + 1;i <= n + m * n; i++) add(i, ed, 1, 0);
}
int spfa()
{
	int i, j, t;
	memset(pre, -1, sizeof(pre));
	for(i = st;i <= ed; i++) dis[i] = oo;
	dis[st] = 0; has[st] = 1;
	que[0] = st; head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head]; has[i] = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].f > 0 && dis[j] > dis[i] + e[t].c)
			{
				dis[j] = dis[i] + e[t].c;
				pre[j] = t;
				if(has[j] == 0)
				{
					has[j] = 1;
					que[tail] = j;
					tail = (tail + 1) % MAXQ;
				}
			}
			t = e[t].next;
		}
		head = (head + 1) % MAXQ;
	}
	return dis[ed] != oo;
}
void solve()
{
	double mincost;
	int i, j;
	mincost = 0.0;
	while(spfa())
	{
		i = ed;
		while(i != st)
		{
			e[pre[i]].f--;
			e[pre[i]^1].f++;
			e[pre[i]^1].c = -e[pre[i]].c;
			i = e[pre[i]].u;
		}
		mincost += dis[ed];
	}
	mincost /= (n * 1.0);
	printf("%0.6lf\n", mincost);
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
