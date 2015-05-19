#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXM 5202
#define MAXN 522
typedef struct{ int u;int v; int f; int next;}edge_t;
edge_t e[MAXM * 2];
int first[MAXN];
int dis[MAXN];
int pre[MAXN];
int cnt[MAXN];
int cur[MAXN];
int has[2][MAXN];
int tot, n;
void add(int u, int v, int f)
{
    e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].next = first[u]; first[u] = tot;
    e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
    int m, i, j, k;
    scanf("%d %d", &n, &m);
    memset(first, -1, sizeof(first));
    tot = -1;
    while (m--)
    {
        scanf("%d %d %d", &i, &j, &k);
        add(i, j, k);
    }
}
void sap()
{
    int now_flow, found, min;
    int st, ed, i, j, t;
    memset(dis, 0, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    st = 0;
    ed = n - 1;
    i = st;
    now_flow = oo;
    cnt[0] = n;
    while (dis[st] < n)
    {
        cur[i] = now_flow;
        found = 0;
        t = first[i];
        while (t != -1)
        {
            j = e[t].v;
            if (e[t].f > 0 && dis[j] + 1 == dis[i])
            {
                found = 1;
                if (e[t].f < now_flow) now_flow = e[t].f;
                pre[j] = t;
                i = j;
                if (i == ed)
                {
                    while (i != st)
                    {
                        e[pre[i]].f -= now_flow;
                        e[pre[i]^1].f += now_flow;
                        i = e[pre[i]].u;
                    }
                    now_flow = oo;
                }
                break;
            }
            t = e[t].next;
        }
        if (found) continue;
        if (--cnt[dis[i]] == 0) break;
        min = n - 1;
        t = first[i];
        while (t != -1)
        {
            if (e[t].f > 0 && dis[e[t].v] < min) min = dis[e[t].v];
            t = e[t].next;
        }
        dis[i] = min + 1;
        cnt[dis[i]]++;
        if (i != st)
        {
            i = e[pre[i]].u;
            now_flow = oo;
        }
    }
}
void dfs(int st, int flag)
{
	int t, j;
	cnt[st] = 1;
	has[flag][st] = 1;
	t = first[st];
	while(t != -1)
	{
		j = e[t ^ flag].v;
		if(e[t ^ flag].f > 0 && cnt[j] == 0) dfs(j, flag);
		t = e[t].next;
	}
}
void solve()
{
	int i, k;
	memset(has, 0, sizeof(has));
	memset(cnt, 0, sizeof(cnt));
	dfs(0, 0);
	memset(cnt, 0, sizeof(cnt));
	dfs(n-1, 1);
	k = 0;
	for(i = 0;i < tot; i += 2)
	{
		if(has[0][e[i].u] && has[1][e[i].v]) k++;
	}
	printf("%d\n", k);
}
int main()
{
    init();
    sap();
    solve();
	return 0;
}
