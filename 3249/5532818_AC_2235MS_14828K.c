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
long long d[MAXN], ans;
int profit[MAXN];
int first[MAXN];
int visited[MAXN];
int que[MAXN];
int out[MAXN];
int in[MAXN];
int head;
int tail;
int tot;
int n, m;
void add(int u, int v)
{
	e[++tot].u = u; e[tot].v = v;
	e[tot].next = first[u]; first[u] = tot;
}
int max(int a, int b) { return a > b ? a : b;}
void topsort()
{
	int i, j, t;
	head = 0; tail = 0; ans = oo;
	for(i = 1;i <= n; i++)
	{
		if(in[i] == 0) 
		{
			que[tail++] = i;
			d[i] = profit[i];
		}
		else d[i] = oo;
	}
	while(head < tail)
	{
		i = que[head];
		if(out[i] == 0 && ans < d[i]) ans = d[i];
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			d[j] = max(d[j], d[i] + profit[j]);
			in[j]--;
			if(in[j] == 0) que[tail++] = j;
			t = e[t].next;
		}
		head++;
	}
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
		topsort();
		printf("%lld\n", ans);
	}
	return 0;
}
