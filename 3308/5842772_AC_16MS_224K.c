#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#define oo DBL_MAX
#define eps 1e-12
#define MAXM 1008
#define MAXN 108
typedef struct
{
	int u; int v; int next;
	double cap;
}edge_t;
edge_t e[MAXM * 2];
double cur[MAXN];
int first[MAXN];
int dist[MAXN];
int now[MAXN];
int pre[MAXN];
int cnt[MAXN];
int tot, st, ed, n, m;
int dcmp(double x)
{
	if(fabs(x) < eps) return 0;
	return (x > 0 ? 1 : -1);
}
void add(int u, int v, double cap)
{
	e[++tot].u = u; e[tot].v = v; e[tot].cap = cap; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].cap = 0.0; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	double k;
	int i, j, l;
	scanf("%d %d %d", &n, &m, &l);
	memset(first, -1, sizeof(first));
	tot = -1; st = 0; ed = n + m + 1;
	for(i = 1;i <= n; i++)
	{
		scanf("%lf", &k);
		add(st, i, log(k));
	}
	for(i = 1;i <= m; i++)
	{
		scanf("%lf", &k);
		add(n + i, ed, log(k));
	}
	while(l--)
	{
		scanf("%d %d", &i, &j);
		add(i, n + j, oo);
	}
	n = n + m + 2;
}
double sap()
{
	double tot_flow, now_flow;
	int found, min;
	int i, j, t;
	memset(dist, 0, sizeof(dist));
	memset(now, -1, sizeof(now));
	memset(cnt, 0, sizeof(cnt));
	i = st;
	tot_flow = 0.0; now_flow = oo;
	cnt[0] = n;
	while(dist[st] < n)
	{
		cur[i] = now_flow; found = 0;
		if(now[i] == -1) t = first[i];
		else t = now[i];
		while(t != -1)
		{
			j = e[t].v;
			if(dcmp(e[t].cap) == 1 && dist[j] + 1 == dist[i])
			{
				found = 1; now[i] = t;
				if(dcmp(e[t].cap - now_flow) == -1) now_flow = e[t].cap;
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
			if(dcmp(e[t].cap) == 1 && dist[e[t].v] < min)
			{
				min = dist[e[t].v];
				now[i] = t;
			}
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

int main()
{
	double res;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		res = sap();
		printf("%0.4lf\n", exp(res));
	}
	return 0;
}
