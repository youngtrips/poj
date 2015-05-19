#

#include <stdio.h>
#define MAX 410
int adj[MAX][MAX], visited[MAX], pre[MAX];
int q[MAX * MAX], head, tail, st, ed, n, m;
void init()
{
	int i, j, s;
	for(i = 0;i < MAX; i++)
		for(j = 0;j < MAX; j++) adj[i][j] = 0;
	ed = n + m + 1;
	st = 0;
	for(i = 1;i <= n; i++) adj[st][i] = 1;
	for(i = n + 1;i <= n + m; i++) adj[i][ed] = 1;
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &s);
		while(s--)
		{
			scanf("%d", &j);
			adj[i][j+n] = 1;
		}
	}
}
int bfs(int st)
{
	int i, k;
	for(i = st; i <= ed; i++) {visited[i] = 0; pre[i] = -1;}
	visited[st] = 1;
	q[0] = st;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		k = q[head];
		for(i = st;i <= ed; i++)
		{
			if(adj[k][i] > 0 && visited[i] == 0 && i != st)
			{
				pre[i] = k;
				visited[i] = 1;
				q[tail++] = i;
				if(i == ed) return 1;
			}
		}
		head++;
	}
	return -1;
}
void ford()
{
	int max = 0, i, j;
	while(bfs(st) != -1)
	{
		max++;
		i = ed;
		while(pre[i] != -1)
		{
			j = pre[i];
			adj[j][i]--;
			adj[i][j]++;
			i = pre[i];
		}
	}
	printf("%d\n", max);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		init();
		ford();
	}
	return 0;
}
