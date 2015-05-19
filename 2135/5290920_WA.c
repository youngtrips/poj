#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAX 2024
int adj[MAX][MAX], cost[MAX][MAX], n;
int q[MAX], ecost[MAX], pre[MAX], head, tail;
void init()
{
	int i, j, k, m;
	scanf("%d %d", &n, &m);
	memset(cost, 0, sizeof(cost));
	memset(adj, 0, sizeof(adj));
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &k);
		adj[i][j] = 1;
		adj[j][i] = 1;
		cost[i][j] = k;
		cost[j][i] = k;
	}
	adj[0][1] = 2;
	adj[n][n+1] = 2;
	n++;
}
int spfa()
{
	int i, j;
	memset(pre, -1, sizeof(pre));
	for(i = 0;i <= n; i++) ecost[i] = oo;
	ecost[0] = 0;
	q[0] = 0;
	head = 0;
	tail = 1;
	while(head < tail)
	{

		i = q[head];
		for(j = 0;j <= n; j++)
		{
			if(adj[i][j] && ecost[j] > ecost[i] + cost[i][j])
			{
				ecost[j] = ecost[i] + cost[i][j];
				pre[j] = i;
				q[tail++] = j;
			}
		}
		head++;
	}
	return ecost[n] != oo;
}
int min_cost_flow()
{
	int mincost = 0, i;
	while(spfa())
	{
		i = n;
		while(pre[i] != -1)
		{
			adj[pre[i]][i]--;
			adj[i][pre[i]]++;
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
	init();
	res = min_cost_flow();
	printf("%d\n", res);
	return 0;
}
