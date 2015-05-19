#include <stdio.h>
#include <string.h>
#define MAXM 1000002
#define MAXN 100002
typedef struct
{
	int u; int v;
	int next;
}edge_t;
edge_t e[MAXM];
long long d[MAXN];
int profit[MAXN];
int first[MAXN];
int out[MAXN];
int in[MAXN];
int tot;
int n, m;
void add(int u, int v)
{
	e[++tot].u = u; e[tot].v = v;
	e[tot].next = first[u]; first[u] = tot;
}
int init()
{
	int i, u, v;
	if(scanf("%d %d", &n, &m) == EOF) return 0;
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
	return 1;
}
int max(int a, int b) { return a > b ? a : b;}
void solve()
{
	long long ans;
	int i, j, t;
	for(i = 1;i <= n; i++) if(in[i] == 0) d[i] = profit[i];
	for(i = 1;i <= n; i++)
	{
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			d[j] = max(d[j], d[i] + profit[j]);
			t = e[t].next;
		}
	}
	ans = 0;
	for(i = 1;i <= n; i++) if(out[i] == 0 && ans < d[i]) ans = d[i];
	printf("%lld\n", ans);
}
int main()
{
	while(init()) solve();
	return 0;
}
