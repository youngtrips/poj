#include <stdio.h>
#include <string.h>
#define SQR(x) ((x)*(x))
#define eps 1e-12
#define oo 0x7fffffff
#define MAXM 10002
#define MAXN 102
typedef struct{int u; int v; int cap; int next;}edge_t;
edge_t e[MAXM * 20];
double x[MAXN], y[MAXN], maxl;
int first[MAXN * 2];
int dist[MAXN * 2];
int pre[MAXN * 2];
int cnt[MAXN * 2];
int cur[MAXN * 2];
int ni[MAXN];
int mi[MAXN];
int tot, sum, num, n;
void add(int u, int v, int cap)
{
	e[++tot].u = u; e[tot].v = v; e[tot].cap = cap; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].cap = 0; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int i, j;
	scanf("%d %lf", &n, &maxl);
	for(i = 1;i <= n; i++) scanf("%lf %lf %d %d", &x[i], &y[i], &ni[i], &mi[i]);
	num = n;
}
void build()
{
	int i, j;
	memset(first, -1, sizeof(first)); tot = -1; sum = 0;
	for(i = 1;i <= num; i++) add(2 * i - 1, 2 * i, mi[i]);
	for(i = 1;i <= num; i++)
	{
		sum += ni[i];
		for(j = 1;j <= num; j++)
		{
			if(i == j) continue;
			if(SQR(x[i] - x[j]) + SQR(y[i] - y[j]) + eps <= SQR(maxl))
			{
				add(2 * i, 2 * j - 1, oo);
			}
		}
	}
	for(i = 1;i <= num; i++) add(0, 2 * i - 1, ni[i]);
	n = 2 * num + 1;
}
int sap(int st, int ed)
{
	int tot_flow;
	int now_flow, found, min;
	int i, j, t;
	memset(dist, 0, sizeof(dist));
	memset(cnt, 0, sizeof(cnt));
	i = st;
	tot_flow = 0; now_flow = oo;
	cnt[0] = n;
	while(dist[st] < n)
	{
		cur[i] = now_flow; found = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].cap > 0 && dist[j] + 1 == dist[i])
			{
				found = 1;
				if(e[t].cap < now_flow) now_flow = e[t].cap;
				pre[j] = t; i = j;
				if(i == ed)
				{
					tot_flow += now_flow;
					while(i != st)
					{
						e[pre[i]].cap -= now_flow;
						e[pre[i]^1].cap += now_flow;
						i = e[pre[i]].u;
					}
					now_flow = oo;
				}
				break;
			}
			t = e[t].next;
		}
		if(found) continue;
		if(--cnt[dist[i]] == 0) break;
		min = n - 1;
		t = first[i];
		while(t != -1)
		{
			if(e[t].cap > 0 && dist[e[t].v] < min) min = dist[e[t].v];
			t = e[t].next;
		}
		dist[i] = min + 1;
		cnt[dist[i]]++;
		if(i != st)
		{
			i = e[pre[i]].u;
			now_flow = cur[i];
		}
	}
	return tot_flow;
}
void solve()
{
	int res, flag, i;
	flag = 1;
	for(i = 1;i <= num; i++)
	{
		build();
		res = sap(0, i * 2 - 1);
		if(res == sum)
		{
			if(flag) printf("%d", i - 1);
			else printf(" %d", i - 1);
			flag = 0;
		}
	}
	if(flag == 0) printf("\n");
	else printf("-1\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}
