#include <stdio.h>
#include <string.h>
#define MAX 102
#define eps 1e-20
int adj[MAX][MAX], n;
double d[MAX];
int init()
{
	int a, b, p, m, i;
	scanf("%d", &n);
	if(n == 0) return 0;
	scanf("%d", &m);
	memset(adj, 0, sizeof(adj));
	while(m--)
	{
		scanf("%d %d %d", &a, &b, &p);
		adj[a][b] = p;
		adj[b][a] = p;
	}
	for(i = 1;i <= n; i++) d[i] = 0;
}
void bellman_ford()
{
	int f, k, i, j;
	d[1] = 1;
	for(k = 1;k < n; k++)
	{
		f = 1;
		for(i = 1;i <= n; i++)
		{
			for(j = 1;j <= n; j++)
			{
				if(adj[i][j] && d[j] + eps < d[i] * adj[i][j] / 100.0)
				{
					d[j] = d[i] * adj[i][j] / 100.0;
					f = 0;
				}
			}
		}
		if(f) break;
	}
}
int main()
{
	double max;
	while(init())
	{
		bellman_ford();
		max = d[n];
		printf("%0.6f percent\n", max * 100.0);
	}
}
