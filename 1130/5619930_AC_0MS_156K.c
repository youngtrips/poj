#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXN 1002
typedef struct{ int v; int f; int next;}edge_t;
edge_t e[MAXN * MAXN];
int visited[MAXN];
int first[MAXN];
int dist[MAXN];
int que[MAXN];
int head, tail;
int tot, et, n;
void add(int u, int v, int f) { e[++tot].v = v; e[tot].f = f; e[tot].next = first[u]; first[u] = tot;}
void init()
{
	int u, v;
	scanf("%d %d", &n, &et);
	memset(first, -1, sizeof(first));
	tot = 0;
	while(scanf("%d %d", &u, &v) != EOF)
	{
	   	add(u, v, 1);
		add(v, u, 0);
	}
}
void spfa()
{
	int i, j, t;
	for(i = 0;i < n; i++) dist[i] = oo;
	memset(visited, 0, sizeof(visited));
	que[0] = et; dist[et] = 0; visited[et] = 1;
	head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head];
		visited[i] = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].f == 0)
			{
				if(dist[j] > dist[i] + 1)
				{
					dist[j] = dist[i] + 1;
					if(visited[j] == 0)
					{
						que[tail++] = j;
						visited[j] = 1;
					}
				}
			}
			t = e[t].next;
		}
		head++;
	}
}
int dfs(int i)
{
	int j, t;
	visited[i] = 1;
	t = first[i];
	while(t != -1)
	{
		j = e[t].v;
		if(e[t].f == 1 && visited[j] == 0) dfs(j);
		t = e[t].next;
	}
}
void solve()
{
	int min, p, i, j;
	min = oo; p = 0;
	for(i = 0;i < n; i++)
	{
		if(i == et) continue;
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		dfs(0);
		if(visited[et] == 0)
		{
			if(dist[i] < min)
			{
				min = dist[i];
				p = i;
			}
		}
	}
	printf("Put guards in room %d.\n", p);
}
int main()
{
	init();
	spfa();
	solve();
	return 0;
}
