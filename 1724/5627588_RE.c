#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 10002
#define MAXN 102
typedef struct { int v; int w; int c; int next;}edge_t;
edge_t e[MAXN];
int first[MAXN];
int que[MAXM * 100][3];
int head, tail;
int tot, dist, max, n;
void add(int u, int v, int w, int c)
{ 
	e[++tot].v = v; e[tot].w = w; e[tot].c = c;
	e[tot].next = first[u]; first[u] = tot;
}
void init()
{
	int m, i, j, l, t;
	scanf("%d %d %d", &max, &n, &m);
	memset(first, -1, sizeof(first));
	tot = 0;
	while(m--)
	{
		scanf("%d %d %d %d", &i, &j, &l, &t);
		add(i, j, l, t);
	}
}
void bfs()
{
	int i, j, l, k, t;
	que[0][0] = 1; que[0][1] = 0; que[0][2] = 0;
	head = 0; tail = 1; dist = oo;
	while(head < tail)
	{
		i = que[head][0]; l = que[head][1]; k = que[head][2];
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(k + e[t].c <= max)
			{
				que[tail][0] = j;
				que[tail][1] = l + e[t].w;
				que[tail][2] = k + e[t].c;
				if(j == n && dist > l + e[t].w) dist = l + e[t].w;
				tail++;
			}
			t = e[t].next;
		}
		head++;
	}
}
int main()
{
	int i;
	init();
	bfs();
	printf("%d\n", (dist == oo ? -1 : dist));
	return 0;
}
