#include <stdio.h>
#include <string.h>
#define MAXM 50002
#define MAXN 10002
struct edge_t
{
	int v;
	struct edge_t* next;
};
struct edge_t list_a[MAXN];
struct edge_t list_t[MAXN];
struct edge_t e[MAXM * 2];
struct edge_t* p;
int visited[MAXN];
int order[MAXN];
int out[MAXN];
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
void init()
{
	int k, i, j;
	scanf("%d %d", &n, &k);
	for(i = 1;i <= n; i++) { list_t[i].next = NULL;list_a[i].next = NULL;}
	p = e;
	while(k--)
	{
		scanf("%d %d", &i, &j);
		insert_a(i, j);
		insert_t(j, i);
	}
}
void dfs_a(int x)
{
	struct edge_t* p;
	visited[x] = 1;
	p = list_a[x].next;
	while(p != NULL)
	{
		if(visited[p->v] == 0) dfs_a(p->v);
		p = p->next;
	}
	order[++cnt] = x;
}
void dfs_t(int x, int no)
{
	struct edge_t* p;
	visited[x] = no;
	p = list_t[x].next;
	while(p != NULL)
	{
		if(visited[p->v] == 0) dfs_t(p->v, no);
		p = p->next;
	}
}
void kosaraju()
{
	int i;
	cnt = 0;
	m = 0;
	memset(visited, 0, sizeof(visited));
	for(i = 1;i <= n; i++) if(visited[i] == 0) dfs_a(i);
	memset(visited, 0, sizeof(visited));
	for(i = cnt;i >= 1; i--) if(visited[order[i]] == 0) dfs_t(order[i], ++m);
}
void shrink()
{
	struct edge_t* p;
	int i, j;
	memset(out, 0, sizeof(out));
	for(i = 1;i <= n; i++)
	{
		p = list_a[i].next;
		while(p != NULL)
		{
			j = p->v;
			if(visited[i] != visited[j])
			{
				out[visited[i]]++;
			}
			p = p->next;
		}
	}
}
void count()
{
	int i, j, k;
	cnt = 0;
	k = 0;
	for(i = 1;i <= m; i++) if(out[i] == 0) { k++; j = i;}
	if(k > 1) {cnt = 0; return;}
	for(i = 1;i <= n; i++) if(visited[i] == j) cnt++;
}
int main()
{
	init();
	kosaraju();
	shrink();
	count();
	printf("%d\n", cnt);
	return 0;
}
