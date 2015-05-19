#include <stdio.h>
#include <string.h>
#define MAX 402
int adj[MAX][MAX], ed;
int q[MAX], pre[MAX], head, tail;
int bfs()
{
	int i, k;
	memset(pre, -1, sizeof(pre));
	q[0] = 0;
	pre[0] = -2;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		k = q[head];
		for(i = 0;i <= ed; i++)
		{
			if(adj[k][i] && pre[i] == -1)
			{
				pre[i] = k;
				if(i == ed) return 1;
				q[tail++] = i;
			}
		}
		head++;
	}
	return 0;
}
int ford()
{
	int cnt = 0, i, j;
	while(bfs())
	{
		j = ed;
		while(pre[j] != -2)
		{
			i = pre[j];
			adj[i][j]--;
			adj[j][i]++;
			j = pre[j];
		}
		cnt++;
	}
	return cnt;
}
void init()
{
	int n, f, d, nf, nd, i, j, k;
	scanf("%d %d %d", &n, &f, &d);
	memset(adj, 0, sizeof(adj));
	ed = n * 2 + f + d + 1;
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &nf, &nd);
		while(nf--)
		{
			scanf("%d", &j);
			adj[j][f + i] = 1; 
		}
		while(nd--)
		{
			scanf("%d", &j);
			adj[n + f + i][2 * n + f + j] = 1; 
		}
	}
	for(i = 1;i <= f; i++) adj[0][i] = 1; 
	for(i = 1;i <= n; i++) adj[i + f][i + n + f] = 1; 
	for(i = 1;i <= d; i++) adj[2 * n + f + i][ed] = 1; 
}
int main()
{
	int res;
	init();
	res = ford();
	printf("%d\n", res);
	return 0;
}
