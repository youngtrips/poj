#include <stdio.h>
#include <string.h>
#define MAX 1002
#define eps 1e-20
#define dist(i,j) ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
char adj[MAX][MAX];
int q[MAX], dis[MAX], head, tail, st, ed, n;
double x[MAX], y[MAX];
int bfs()
{
	int i, k, j;
	memset(dis, -1, sizeof(dis));
	dis[st] = 0;
	q[0] = st;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		i = q[head];
		k = dis[i];
		for(j = 1;j <= n; j++)
		{
			if(adj[i][j] == '1' && dis[j] == -1)
			{
				dis[j] = k + 1;
				if(j == ed) return 1;
				q[tail++] = j;
			}
		}
		head++;
	}
	return 0;
}
int main()
{
	double max, d;
	int v, m, i, j;
	scanf("%d %d", &v, &m);
	scanf("%lf %lf", &x[1], &y[1]);
	scanf("%lf %lf", &x[2], &y[2]);
	st = 1; ed = 2;
	n = 3;
	while(scanf("%lf %lf", &x[n], &y[n]) != EOF) n++;
	n--;
	max = v * v * m * m * 3600.0;
	memset(adj, '0', sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		for(j = i + 1;j <= n; j++)
		{
			d = dist(i, j);
			if(d + eps < max)
			{
				adj[i][j] = '1';
				adj[j][i] = '1';
			}
		}
	}
	if(bfs() == 0) printf("No.\n");
	else printf("Yes, visiting %d other holes.\n", dis[ed] - 1);
	return 0;
}
