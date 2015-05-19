#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXN 102
typedef struct { int v; int next;}edge_t;
edge_t e[MAXN * MAXN];
int first[MAXN];
int ancestor[MAXN];
int color[MAXN];
int deep[MAXN];
int cut[MAXN];
int root, es, n;
void add(int u, int v) { e[++es].v = v; e[es].next = first[u]; first[u] = es;}
void dfs(int k, int pre, int dp)
{
	int tot, i, t;
	color[k] = 1;
	deep[k] = dp;
	ancestor[k] = dp;
	tot = 0;
	t = first[k];
	while(t != -1)
	{
		i = e[t].v;
		if(i != pre && color[i] == 1) ancestor[k] = MIN(ancestor[k], deep[i]);
		if(color[i] == 0)
		{
			dfs(i, k, dp + 1);
			tot++;
			ancestor[k] = MIN(ancestor[k], ancestor[i]);
			if((k == root && tot > 1) || (k != root && ancestor[i] >= deep[k])) cut[k] = 1;
		}
		t = e[t].next;
	}
	color[k] = 2;
}
int init()
{
	char ch;
	int i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
	memset(first, -1, sizeof(first));
	es = 0;
	while(1)
	{
		scanf("%d", &i);
		if(i == 0) break;
		while(1)
		{
			ch = getchar();
			if(ch == '\n') break;
			scanf("%d", &j);
			add(i, j);
			add(j, i);
		}
	}
	return 1;
}
int main()
{
	int cnt, i;
	while(init())
	{
		memset(color, 0, sizeof(color));
		memset(cut, 0, sizeof(cut));
		root = 1; cnt = 0;
		dfs(root, root, 1);
		for(i = 1;i <= n; i++) cnt += cut[i];
		printf("%d\n", cnt);
	}
	return 0;
}
