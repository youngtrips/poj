#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 10002
#define MAXN 10008
typedef struct
{
	int u; int v; int w;
	int next;
}edge_t;
edge_t e[MAXM * 10];
int first[MAXN];
int dist[MAXN];
int que[MAXN * 100];
int has[MAXN];
int head, tail;
int tot, st, ed, n;
void add(int u, int v, int w)
{
	e[++tot].u = u; e[tot].v = v; e[tot].w = w;
	e[tot].next = first[u]; first[u] = tot;
}
void init()
{
	int i, a, b, c;
	memset(first, -1, sizeof(first));
	tot = 0;
	st = 9999999; ed = -1;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		b++;
		if(st > a) st = a;
		if(ed < b) ed = b;
		add(b, a, -2);
	}
	for(i = st;i < ed; i++)
	{
		add(i, i + 1, 1);
		add(i + 1, i, 0);
	}
}
void spfa()
{
	int i, j, t;
	for(i = st;i <= ed; i++) dist[i] = oo;
	memset(has, 0, sizeof(has));
	dist[ed] = 0; has[ed] = 1;
	que[0] = ed;
	head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head];
		has[i] = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(dist[j] > dist[i] + e[t].w)
			{
				dist[j]  = dist[i] + e[t].w;
				if(has[j] == 0)
				{
					que[tail++] = j;
					has[j] = 1;
				}
			}
			t = e[t].next;
		}
		head++;
	}
	printf("%d\n", -dist[st]);
}
int main()
{
	int i;
	init();
	spfa();
	return 0;
}
