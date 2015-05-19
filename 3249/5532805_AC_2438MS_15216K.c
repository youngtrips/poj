#include <stdio.h>
#include <string.h>
#define MAXM 1000002
#define MAXN 100002
#define oo -9999999999999ll
typedef struct
{
	int u; int v;
	int next;
}edge_t;
edge_t e[MAXM];
long long d[MAXN];
int profit[MAXN];
int first[MAXN];
int visited[MAXN];
int order[MAXN];
int out[MAXN];
int in[MAXN];
int tot;
int cnt;
int n, m;
void add(int u, int v)
{
	e[++tot].u = u; e[tot].v = v;
	e[tot].next = first[u]; first[u] = tot;
}
void dfs(int i)
{
	int j, t;
	visited[i] = 1;
	t = first[i];
	while(t != -1)
	{
		j = e[t].v;
		if(visited[j] == 0) dfs(j);
		t = e[t].next;
	}
	order[cnt--] = i;
}
int max(int a, int b) { return a > b ? a : b;}
void solve()
{
	long long ans;
	int i, j, t, k;
	for(i = 1;i <= n; i++) 
		if(in[i] == 0) d[i] = profit[i];
		else d[i] = oo;
	memset(visited, 0, sizeof(visited));
	cnt = n;
	for(i = 1;i <= n; i++) if(visited[i] == 0) dfs(i);
	for(k = 1;k <= n; k++)
	{
		i = order[k];
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			d[j] = max(d[j], d[i] + profit[j]);
			t = e[t].next;
		}
	}
	ans = oo;
	for(i = 1;i <= n; i++) if(out[i] == 0 && ans < d[i]) ans = d[i];
	printf("%lld\n", ans);
}
int main()
{
	int i, u, v;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(i = 1;i <= n; i++) scanf("%d", &profit[i]);
		memset(first, -1, sizeof(first));
		memset(out, 0, sizeof(out));
		memset(in, 0, sizeof(in));
		tot = 0;
		for(i = 1;i <= m; i++)
		{
			scanf("%d %d", &u, &v);
			add(u, v);
			out[u]++; in[v]++;
		}
		solve();
	}
	return 0;
}
