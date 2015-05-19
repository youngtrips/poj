#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAX 210
int adj[MAX][MAX], cost[MAX][MAX];
int ecost[MAX], has[MAX], pre[MAX], q[MAX], head, tail, n;
void init()
{
	int p, t, u, v, w;
	scanf("%d %d %d", &n, &p, &t);
	memset(adj, 0, sizeof(adj));
	while(p--)
	{
		scanf("%d %d %d", &u, &v, &w);
		cost[u][v] = w;
		cost[v][u] = w;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	adj[0][1] = t;
	adj[n][n + 1] = t;
	n++;
}
int spfa()
{
	int i, j, k;
	memset(pre, -1, sizeof(pre));
	memset(has, 0, sizeof(has));
	for(i = 0;i <= n; i++) ecost[i] = oo;
	ecost[0] = 0;
	has[0] = 1;
	q[0] = 0;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		i = q[head];
		has[i] = 0;
		for(j = 0;j <= n; j++)
		{
			if(adj[i][j] && ecost[j] > ecost[i] + cost[i][j])
			{
				ecost[j] = ecost[i] + cost[i][j];
				pre[j] = i;
				if(has[j] == 0)
				{
					has[j] = 1;
					q[tail++] = j;
				}
			}
		}
		head++;
	}
	return ecost[n] != oo;
}
int min_cost_flow()
{
	int max = 0, i;
	while(spfa())
	{
		i = n;
		while(pre[i] != -1)
		{
			adj[pre[i]][i]--;
			adj[i][pre[i]]++;
			cost[i][pre[i]] = -cost[pre[i]][i];
			if(max < cost[pre[i]][i]) max = cost[pre[i]][i];
			i = pre[i];
		}
	}
	return max;
}
int main()
{
	int res;
	init();
	res = min_cost_flow();
	printf("%d\n", res);
	return 0;
}
