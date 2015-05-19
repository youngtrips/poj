#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 16002
typedef struct
{
	int v;
	int next;
}edge_t;
typedef struct
{
	int x;
	int y;
}pt_t;
edge_t e[MAXN * 2];
pt_t pt[MAXN];
int visited[MAXN];
int first[MAXN];
int ans[MAXN];
int tot;
int cnt;
int n, k;
void add(int u, int v)
{
	e[++tot].v = v; e[tot].next = first[u]; first[u] = tot;
	e[++tot].v = u; e[tot].next = first[v]; first[v] = tot;
}
int cmp(const void* p1, const void* p2)
{
	pt_t* a = (pt_t*)p1;
	pt_t* b = (pt_t*)p2;
	if(a->x == b->x) return a->y - b->y;
	return a->x - b->x;
}
int cmp2(const void* p1, const void* p2)
{
	return *(int*)p2 - *(int*)p1;
}
void init()
{
	int i;
	scanf("%d %d", &n, &k);
	for(i = 1;i <= n; i++) scanf("%d %d", &pt[i].x, &pt[i].y);
	qsort((void*)&pt[1], n, sizeof(pt[1]), cmp);
	memset(first, -1, sizeof(first));
	tot = 0;
	for(i = 2;i <= n; i++)
	{
		if((pt[i-1].x + 1 == pt[i].x && pt[i-1].y == pt[i].y) ||
		   (pt[i-1].x == pt[i].x && pt[i-1].y + 1 == pt[i].y))
			add(i - 1, i);
	}
}
void dfs(int i)
{
	int j, t;
	visited[i] = 1;
	cnt++;
	t = first[i];
	while(t != -1)
	{
		j = e[t].v;
		if(visited[j] == 0) dfs(j);
		t = e[t].next;
	}
}
void solve()
{
	int max, i, j, t;
	memset(visited, 0, sizeof(visited));
	for(i = 1, j = 0;i <= n; i++)
	{
		if(visited[i] == 0)
		{
			cnt = 0;
			dfs(i);
			ans[++j] = cnt;
		}
	}
	qsort((void*)&ans[1], j, sizeof(ans[1]), cmp2);
	max = 0;
	for(i = 1;i <= k; i++) max += ans[i];
	printf("%d\n", max);
}
int main()
{
	init();
	solve();
	return 0;
}
