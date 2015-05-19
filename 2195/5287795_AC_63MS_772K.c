#include <stdio.h>
#include <string.h>
#define oo 99999999
#define MAXN 210
int adj[MAXN][MAXN], cost[MAXN][MAXN], n;
int pre[MAXN], ecost[MAXN];
int mx[MAXN], my[MAXN], hx[MAXN], hy[MAXN], n_m, n_h;
int myabs(int x){ return x < 0 ? (-x) : x;}
int init()
{
	char ch;
	int r, c, i, j;
	scanf("%d %d", &r, &c);
	getchar();
	if(r == 0 && c == 0) return 0;
	n_m = 0; n_h = 0;
	for(i = 1;i <= r; i++)
	{
		for(j = 1;j <= c; j++)
		{
			ch = getchar();
			if(ch == 'm'){mx[++n_m] = i; my[n_m] = j;}
			if(ch == 'H'){hx[++n_h] = i; hy[n_h] = j;}
		}
		getchar();
	}
	n = n_m + n_m + 1;
	memset(cost, 0, sizeof(cost));
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n_m; i++)
	{
		adj[0][i] = 1;
		adj[i + n_m][n] = 1;
	}
	for(i = 1;i <= n_m; i++)
	{
		for(j = 1;j <= n_h; j++)
		{
			c = myabs(mx[i] - hx[j]) + myabs(my[i] - hy[j]);
			cost[i][j + n_m] = c;
			adj[i][j + n_m] = 1;
		}
	}
	return 1;
}
int bellman_ford()
{
	int flag, i, j;
	memset(pre, -1, sizeof(pre));
	for(i = 0;i <= n; i++) ecost[i] = oo;
	ecost[0] = 0;
	while(1)
	{
		flag = 0;
		for(i = 0;i <= n; i++)
		{
			if(ecost[i] == oo) continue;
			for(j = 0;j <= n; j++)
			{
				if(adj[i][j] && ecost[j] > ecost[i] + cost[i][j])
				{
					ecost[j] = ecost[i] + cost[i][j];
					pre[j] = i;
					flag = 1;
				}
			}
		}
		if(flag == 0) break;
	}
	return ecost[n] != oo;
}
int min_cost_flow()
{
	int mincost = 0;
	int neck = 1, i, j;
	while(bellman_ford())
	{
		i = n;
		while(pre[i] != -1)
		{
			adj[pre[i]][i] -= neck;
			adj[i][pre[i]] += neck;
			cost[i][pre[i]] = -cost[pre[i]][i];
			mincost += cost[pre[i]][i];
			i = pre[i];
		}
	}
	return mincost;
}
int main()
{
	int res;
	while(init())
	{
		res = min_cost_flow();
		printf("%d\n", res);
	}
	return 0;
}
