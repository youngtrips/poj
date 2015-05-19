#include <stdio.h>
#include <string.h>
#define MAXM 10000002
#define MAXN 100002
typedef struct
{
	int v; int next;
}edge_t;
edge_t e[MAXM];
int first[MAXN];
int que[MAXN * 2];
int dis[MAXN];
int head, tail;
int tot, st, ed, n;
void add(int u, int v)
{
	e[++tot].v = v; e[tot].next = first[u]; first[u] = tot;
}
void init()
{
	int i, j, k, t;
	scanf("%d", &n);
	memset(first, -1, sizeof(first));
	tot = -1;
	for(k = 1;k <= n; k++)
	{
		scanf("%d %d", &i, &t);
		while(t--)
		{
			scanf("%d", &j);
			add(i, j);
		}
	}
	scanf("%d %d", &st, &ed);
}
int bfs()
{
	int i, j, t;
	memset(dis, -1, sizeof(dis));
	dis[st] = 0;
	que[0] = st;
	head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head];
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(j == ed) return dis[i];
			if(dis[j] == -1)
			{
				dis[j] = dis[i] + 1;
				que[tail++] = j;
			}
			t = e[t].next;
		}
		head++;
	}
	return -1;
}
int main()
{
	int res;
	init();
	res = bfs();
	printf("%d %d %d\n", st, ed, res);
	return 0;
}
