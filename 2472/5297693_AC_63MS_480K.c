#include <stdio.h>
#include <string.h>
#define eps 1e-20
#define MAX 102
int adj[MAX][MAX], n;
int q[MAX * MAX], head, tail;
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
	for(i = 1;i <= n; i++) d[i] = 0.0;
	d[1] = 1.0;
	q[0] = 1;
	head = 0; tail = 1;
}
void spfa()
{
	int i, j;
	while(head < tail)
	{
		i = q[head];
		for(j = 1;j <= n; j++)
		{
			if(adj[i][j] && d[j] + eps < d[i] * adj[i][j] / 100.0)
			{
				d[j] = d[i] * adj[i][j] / 100.0;
				q[tail++] = j;
			}
		}
		head++;
	}
}
int main()
{
	while(init())
	{
		spfa();
		printf("%0.6f percent\n", d[n] * 100.0);
	}
	return 0;
}
