#include <stdio.h>
#include <string.h>
#define MAXE 100002
#define MAXN 10002
typedef struct
{
	int u; int v; int next;
}edge_t;
edge_t e[MAXE];
char visited[MAXE];
int stack[MAXE];
int first[MAXN];
int top;
int tot;
int n;
void add(int u, int v)
{
	e[++tot].u = u; e[tot].v = v; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	memset(first, -1, sizeof(first)); tot = -1;
	while(m--)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
}
void find_euler(int u)
{
	int t, v;
	t = first[u];
	while(t != -1)
	{
		v = e[t].v;
		if(visited[t] == 0)
		{
			visited[t] = 1;
			find_euler(v);
			stack[++top] = t;
		}
		t = e[t].next;
	}
}
int main()
{
	int i, k;
	init();
	memset(visited, 0, sizeof(visited));
	tot = 0;
	find_euler(1);
	k = -1;
	while(top > 0)
	{
		i = stack[top];
		if(k == e[i].u) printf("%d\n", e[i].v);
		else printf("%d\n%d\n", e[i].u, e[i].v);
		k = e[i].v;
		top--;
	}
	return 0;
}
