#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXN 1508
typedef struct
{
	int u; int v; int cap; int next;
}edge_t;
edge_t e[MAXN * MAXN];
char adj[1002][502];
int first[MAXN];
int dist[MAXN];
int now[MAXN];
int pre[MAXN];
int cnt[MAXN];
int cur[MAXN];
int in[502];
int tot, st, ed;
int n2, n, m;
void add(int u, int v, int cap)
{
	e[++tot].u = u; e[tot].v = v; e[tot].cap = cap; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].cap = 0;   e[tot].next = first[v]; first[v] = tot;
}
int init()
{
	char ch;
	int i, j;
	scanf("%d %d", &n, &m);
	if(n == 0 && m == 0) return 0;
	memset(adj, 0, sizeof(adj));
	memset(in, 0, sizeof(in));
	st = 0; ed = n + m + 1; n2 = n;
	getchar();
	for(i = 1;i <= n; i++)
	{
		ch = getchar();
		while((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ch = getchar();
		while(ch == ' ') ch = getchar();
		while(1)
		{
			j = 0;
			while(ch >= '0' && ch <= '9')
			{
				j = j * 10 + ch - '0';
				ch = getchar();
			}
			adj[i][j + 1] = 1;
			in[j + 1]++;
			if(ch == '\n') break;
			while(ch == ' ') ch = getchar();
		}
	}
	n = n + m + 2;
	return 1;
}
void build(int lmt)
{
	int i, j;
	memset(first, -1, sizeof(first)); tot = -1;
	for(i = 1;i <= n2; i++)
	{
		add(st, i, 1);
		for(j = 1;j <= m; j++) if(adj[i][j] == 1) add(i, n2 + j, 1);
	}
	for(i = 1;i <= m; i++)
		if(in[i] > lmt) add(i + n2, ed, lmt);
		else add(i + n2, ed, in[i]);
}
int sap()
{
	int tot_flow;
	int now_flow, found, min;
	int i, j, t;
	memset(dist, 0, sizeof(dist));
	memset(now, -1, sizeof(now));
	memset(cnt, 0, sizeof(cnt));
	i = st;
	tot_flow = 0; now_flow = oo;
	cnt[0] = n;
	while(dist[st] < n)
	{
		cur[i] = now_flow; found = 0;
		if(now[i] == -1) t = first[i];
		else t = now[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].cap > 0 && dist[j] + 1 == dist[i])
			{
				found = 1; now[i] = t;
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
			if(e[t].cap > 0 && dist[e[t].v] < min)
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
void solve()
{
	int high = n2;
	int low = 0;
	int mid;
	int res;
	while(low < high)
	{
		mid = (low + high) >> 1;
		build(mid);
		res = sap();
		if(res >= n2) high = mid;
		else low = mid + 1;
	}
	printf("%d\n", low);
}
int main()
{
	while(init()) solve();
	return 0;
}
