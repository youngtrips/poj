#include <stdio.h>
#include <string.h>
#define MAXM 2000002
#define MAXN 10002
typedef struct{int v; int next;} edge_t;
edge_t e[MAXM];
int first[MAXN], tot, cnt, n;
int q[MAXN], visited[MAXN], bad[MAXN], head, tail;
void add(int u, int v)
{
	++tot;
	e[tot].v = v;
	e[tot].next = first[u]; first[u] = tot;
	++tot;
	e[tot].v = u;
	e[tot].next = first[v]; first[v] = tot;
}
void set_bad(int u)
{
	int t;
	memset(bad, 0, sizeof(bad));
	t = first[u];
	while(t != -1)
	{
		bad[e[t].v] = 1;
		t = e[t].next;
	}
}
void bfs()
{
	int i, j;
	while(head < tail)
	{
		i = q[head];
		set_bad(i);
		for(j = 1;j <= n; j++)
		{
			if(visited[j] == 0 && bad[j] == 0)
			{
				visited[j] = 1;
				q[tail++] = j;
				cnt++;
			}
		}
		head++;
	}
}
int main()
{
	int m, i, j, s = 1;
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		memset(first, -1, sizeof(first));
		tot = 0;
		while(m--)
		{
			scanf("%d %d", &i, &j);
			add(i, j);
		}
		memset(visited, 0, sizeof(visited));
		visited[1] = 1;
		q[0] = 1; head = 0; tail = 1;
		cnt = 0;
		bfs();
		printf("Case %d: %d\n", s++, cnt);
	}
	return 0;
}
