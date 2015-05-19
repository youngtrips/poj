#include <stdio.h>
#define MAX 202
int adj[MAX][MAX];
int visited[MAX], pre[MAX], min, n;
int queue[MAX * MAX], head, tail;
void init()
{
	int m, i, j, c;
	scanf("%d %d", &m, &n);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) adj[i][j] = 0;
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &c);
		adj[i][j] = c;
	}
}
int bfs(int st)
{
	int i, k;
	queue[0] = st;
	head = 0;
	tail = 1;
	visited[st] = 1;
	for(i = 1;i <= n; i++) { visited[i] = 0; pre[i] = -1;}
	min = 99999999;
	while(head < tail)
	{
		k = queue[head];
		for(i = 1;i <= n; i++)
		{
			if(adj[k][i] > 0 && visited[i] == 0) 
			{
				pre[i] = k;
				visited[i] = 1;
				queue[tail++] = i;
				if(min > adj[k][i]) min = adj[k][i];
				if(i == n) return min;
			}
		}
		head++;
	}
	return -1;
}
void ford()
{
	__int64 max_flow;
	int i, j;
	max_flow = 0;
	while(bfs(1) != -1)
	{
		max_flow += min;
		i = n;
		while(pre[i] != -1)
		{
			j = pre[i];
			adj[j][i] -= min;
			i = pre[i];
		}
	}
	printf("%I64d\n", max_flow);
}
int main()
{
	init();
	ford();
	return 0;
}
