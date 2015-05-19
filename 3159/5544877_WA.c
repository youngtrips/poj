#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 150002
#define MAXN 30002
typedef struct
{
	int u; int v; int w;
	int next;
}edge_t;
edge_t e[MAXM];
int first[MAXN];
int que[MAXN];
int has[MAXN];
int d[MAXN];
int head, tail;
int tot, n;
void add(int u, int v, int w)
{
	e[++tot].u = u; e[tot].v = v; e[tot].w = w;
	e[tot].next = first[u]; first[u] = tot;
}
void spfa()
{
	int i, j, t;
	for(i = 1;i <= n; i++) d[i] = oo;
	memset(has, 0, sizeof(has));
	d[1] = 0; has[1] = 1;
	que[0] = 1;
	head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head];
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(d[j] > d[i] + e[t].w)
			{
				d[j] = d[i] + e[t].w;
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
	printf("%d\n", d[n]);
}
int main()
{
	int m, a, b, c;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(first, -1, sizeof(first));
		tot = 0;
		while(m--)
		{
			scanf("%d %d %d", &a, &b, &c);
			add(a, b, c);
		}
		spfa();
	}
	return 0;
}
