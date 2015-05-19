#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXN 50002
typedef struct
{
	int u; int v; int w;
	int next;
}edge_t;
edge_t e[MAXN * 4];
int first[MAXN];
int dist[MAXN];
int que[MAXN * 20];
int has[MAXN];
int head, tail;
int tot;
int n;
void add(int u, int v, int w)
{
	e[++tot].u = u; e[tot].v = v; e[tot].w = w;
	e[tot].next = first[u]; first[u] = tot;
}
void init()
{
	int m, i, a, b, c;
	memset(first, -1, sizeof(first));
	tot = 0; n = -1;
	scanf("%d", &m);
	for(i = 1;i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		add(b, a-1, -c);
		if(n < b) n = b;
	}
	for(i = 1;i <= n; i++)
	{
		add(i-1, i, 1);
		add(i, i-1, 0);
	}
}
void spfa()
{
	int i, j, t;
	for(i = 0;i <= n; i++) dist[i] = oo;
	memset(has, 0, sizeof(has));
	dist[n] = 0;
	has[n] = 1;
	que[0] = n;
	head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head];
		has[i] = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(dist[i] + e[t].w < dist[j])
			{
				dist[j] = dist[i] + e[t].w;
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
	printf("%d\n", -dist[0]);
}
int main()
{
	init();
	spfa();
	return 0;
}
