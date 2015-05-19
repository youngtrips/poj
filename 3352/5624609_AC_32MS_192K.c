#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXM 1202
#define MAXN 1202
typedef struct { int v; int next;}edge_t;
edge_t e[MAXN + MAXN];
int first[MAXN];
int visited[MAXN];
int low[MAXN];
int pre[MAXN];
int deg[MAXN];
int root, cnt, tot, n;
void add(int u, int v) { e[++tot].v = v; e[tot].next = first[u]; first[u] = tot;}
void dfs(int i, int j)
{
    int t;
    visited[i] = 1;
    pre[i] = cnt; low[i] = cnt++;
    t = first[i];
    while(t != -1)
    {
        if(e[t].v != j)
        {
            if(visited[e[t].v] == 0) dfs(e[t].v, i);
            low[i] = MIN(low[i], low[e[t].v]);
        }
        t = e[t].next;
    }
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
	int ans, i, j, t;
	while(init())
	{
		memset(visited, 0, sizeof(visited));
		root = 1; cnt = 0;
		dfs(root, root);
		memset(deg, 0, sizeof(deg));
		for(i = 1;i <= n; i++)
		{
		    t = first[i];
		    while(t != -1)
		    {
		        j = e[t].v;
		        if(low[i] != low[j]) deg[low[i]]++;
		        t = e[t].next;
		    }
		}
		for(ans = 0, i = 0;i <= n; i++) if(deg[i] == 1) ans++;
		printf("%d\n", (ans + 1) >> 1);
	}
	return 0;
}
