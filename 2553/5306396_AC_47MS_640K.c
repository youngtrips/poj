#include <stdio.h>
#include <string.h>
#define MAXM 50002
#define MAXN 5002
struct edge_t
{
	int v;
	struct edge_t* next;
};
struct edge_t list_a[MAXN];
struct edge_t list_t[MAXN];
struct edge_t e[MAXM];
struct edge_t* p;
int visited[MAXN];
int order[MAXN];
int out[MAXN];
int ans[MAXN];
int cnt, n, m;
void insert_a(int u, int v)
{
	struct edge_t* cur = p++;
	cur->next = list_a[u].next;
	cur->v = v;
	list_a[u].next = cur;
}
void insert_t(int u, int v)
{
	struct edge_t* cur = p++;
	cur->next = list_t[u].next;
	cur->v = v;
	list_t[u].next = cur;
}
int init()
{
	int i, j, k;
	scanf("%d", &n); if(n == 0) return 0;
	scanf("%d", &k);
	p = e;
	for(i = 1;i <= n; i++) { list_a[i].next = NULL; list_t[i].next = NULL;}
	while(k--)
	{
		scanf("%d %d", &i, &j);
		insert_a(i, j);
		insert_t(j, i);
	}
}
void dfs_a(int x)
{
	struct edge_t* cur = list_a[x].next;
	visited[x] = 1;
	while(cur != NULL)
	{
		if(visited[cur->v] == 0) dfs_a(cur->v);
		cur = cur->next;
	}
	order[++cnt] = x;
}
void dfs_t(int x, int no)
{
	struct edge_t* cur = list_t[x].next;
	visited[x] = no;
	while(cur != NULL)
	{
		if(visited[cur->v] == 0) dfs_t(cur->v, no);
		cur = cur->next;
	}
}
void kosaraju()
{
	int i;
	memset(visited, 0, sizeof(visited));
	cnt = 0; m = 0;
	for(i = 1;i <= n; i++) if(visited[i] == 0) dfs_a(i);
	memset(visited, 0, sizeof(visited));
	for(i = cnt;i >= 1; i--) if(visited[order[i]] == 0) dfs_t(order[i], ++m);
}
void scan()
{
	struct edge_t* t;
	int top, i, j;
	memset(out, 0, sizeof(out));
	for(i = 1;i <= n; i++)
	{
		t = list_a[i].next;
		while(t != NULL)
		{
			j = t->v;
			if(visited[i] != visited[j]) out[visited[i]]++;
			t = t->next;
		}
	}
	top = 0;
	cnt = 0;
	memset(order, 0, sizeof(visited));
	for(i = 1;i <= m; i++) if(out[i] == 0) { order[i] = 1; cnt++;}
	if(cnt == 0) printf("\n");
	else
	{
		for(i = 1;i <= n; i++) if(order[visited[i]]) ans[++top] = i;
		for(i = 1;i < top; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[i]);
	}
}
int main()
{
	while(init())
	{
		kosaraju();
		scan();
	}
	return 0;
}
