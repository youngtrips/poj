#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAX_COW 1002
#define MAX_BAR 22
#define MAXN MAX_COW+MAX_BAR+2

int cows[MAX_COW][MAX_BAR];
int adj[MAXN][MAXN];
int bar[MAX_BAR];
int dis[MAXN];
int cnt[MAXN];
int pre[MAXN];
int cur[MAXN];
int num, n, b;

void init()
{
    int i, j, k;
    scanf("%d %d", &n, &b);
    for (i = 1;i <= n; i++)
        for (j = 1;j<= b; j++) scanf("%d", &cows[i][j]);
    for (i = 1;i <= b; i++) scanf("%d", bar + i);
    num = n + b + 2;
}
void build(int low, int high)
{
    int i, j;
    memset(adj, 0, sizeof(adj));
    for (i = 1;i <= n; i++)
    {
        for (j = low;j <= high; j++) adj[i][n + cows[i][j]] = 1;
        adj[0][i] = 1;
    }
	for(i = 1;i <= b; i++) adj[n + i][n+b+1] = bar[i];
}
int sap()
{
    int tot_flow, now_flow, found;
    int min, s, t, i, j;
    memset(dis, 0, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    s = 0;
    t = num - 1;
    i = s;
    now_flow = oo;
    tot_flow = 0;
    cnt[0] = num;
    while (dis[s] < num)
    {
        cur[i] = now_flow;
        found = 0;
        for (j = 0;j < num; j++)
        {
            if (adj[i][j] > 0 && dis[j] + 1 == dis[i])
            {
                found = 1;
                if (adj[i][j] < now_flow) now_flow = adj[i][j];
                pre[j] = i;
                i = j;
                if (i == t)
                {
                    tot_flow += now_flow;
                    while (i != s)
                    {
                        adj[pre[i]][i] -= now_flow;
                        adj[i][pre[i]] += now_flow;
                        i = pre[i];
                    }
                    now_flow = oo;
                }
                break;
            }
        }
        if (found) continue;
        if (--cnt[dis[i]] == 0) break;
        min = num - 1;
        for (j = 0;j < num; j++)
            if (adj[i][j] > 0 && dis[j] < min) min = dis[j];
        dis[i] = min + 1;
        cnt[dis[i]]++;
        if (i != s)
        {
            i = pre[i];
            now_flow = cur[i];
        }
    }
    return tot_flow;
}
void debug()
{
	int i, j;
	for(i = 0;i < num; i++)
	{
		for(j = 0;j < num; j++) printf("%d ", adj[i][j]);
		printf("\n");
	}
}
void solve()
{
	int ans, tmp, i, j;
	ans = oo; i = 1; j = 1;
	while(i <= j && j <= b)
	{
		build(i, j);
		tmp = sap();
		if(tmp == n)
		{
			if(ans > j - i + 1) ans = j - i + 1;
			i++;
		}
		else j++;
	}
	printf("%d\n", ans);
}
int main()
{
    init();
    solve();
    return 0;
}
