#include <stdio.h>
#include <string.h>
#define MAXM 10002
#define MAXN 52
typedef struct
{
	int u;
	int v;
	int p;
	int next;
}edge_t;
edge_t e[MAXM];
char visited[MAXM];
int stack[MAXM];
int first[MAXN];
int deg[MAXN];
int top;
int tot;
int st, n;
void add(int u, int v, int p)
{
	e[++tot].u = u; e[tot].v = v; e[tot].p = p; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].p = p; e[tot].next = first[v]; first[v] = tot;
}
int init()
{
	int i, j, k;
	scanf("%d %d", &i, &j);
	if(i == 0 && j == 0) return 0;
	memset(first, -1, sizeof(first));
	memset(deg, 0, sizeof(deg));
	tot = -1;
	st = (i < j ? i : j);
	n = (i > j ? i : j);
	scanf("%d", &k);
	while(1)
	{
		add(i, j, k);
		deg[i]++;
		deg[j]++;
		if(i > n) n = i;
		if(j > n) n = j;
		scanf("%d %d", &i, &j);
		if(i == 0 && j == 0) break;
		scanf("%d", &k);
		add(i, j, k);
	}
	return 1;
}
void find_euler(int u)
{
	int p, v, t;
	t = first[u];
	while(t != -1)
	{
		v = e[t].v;
		p = e[t].p;
		if(visited[p] == 0)
		{
			visited[p] = 1;
			find_euler(v);
			stack[++top] = p;
		}
		t = e[t].next;
	}
}
int has_euler_path()
{
	int i;
	for(i = 1;i <= n; i++) if(deg[i] & 1) return 0;
	return 1;
}
int main()
{
	while(init())
	{
		if(has_euler_path() == 0)
		{
			printf("Round trip does not exist.\n");
			continue;
		}
		memset(visited, 0, sizeof(visited));
		top = 0;
		find_euler(st);
		while(top > 1) printf("%d ", stack[top--]);
		printf("%d\n", stack[1]);
	}
	return 0;
}
