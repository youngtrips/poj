#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXM 1202
#define MAXN 1202
typedef struct { int v; int next;}edge_t;
edge_t e[MAXN + MAXN];
int brige[MAXN][MAXN];
int first[MAXN];
int ancestor[MAXN];
int color[MAXN];
int deep[MAXN];
int root, tot, n;
void add(int u, int v) { e[++tot].v = v; e[tot].next = first[u]; first[u] = tot;}
void dfs(int k, int pre, int dp)
{
	int i, t;
	color[k] = 1;
	deep[k] = dp;
	ancestor[k] = dp;
	t = first[k];
	while(t != -1)
	{
		i = e[t].v;
		if(i != pre && color[i] == 1) ancestor[k] = MIN(ancestor[k], deep[i]);
		if(color[i] == 0)
		{
			dfs(i, k, dp + 1);
			ancestor[k] = MIN(ancestor[k], ancestor[i]);
			if(ancestor[i] > deep[k]) brige[i][k] = brige[k][i] = 1;
		}
		t = e[t].next;
	}
	color[k] = 2;
}
int init()
{
	int m, i, j;
	if(scanf("%d %d", &n, &m) == EOF) return 0;
	memset(first, -1, sizeof(first));
	tot = 0;
	while(m--)
	{
		scanf("%d %d", &i, &j);
		add(i, j);
		add(j, i);
	}
	return 1;
}
int main()
{
	int tmp, ans, i, j;
	while(init())
	{
		memset(brige, 0, sizeof(brige));
		memset(color, 0, sizeof(color));
		root = 1; ans  = 0;
		dfs(root, root, 1);
		for(i = 1;i <= n; i++)
		{
			tmp = 0;
			for(j = 1;j <= n; j++) tmp += brige[i][j];
			if(tmp == 1) ans++;
		}
		printf("%d\n", (ans + 1) / 2);
	}
	return 0;
}
