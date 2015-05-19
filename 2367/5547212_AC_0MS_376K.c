#include <stdio.h>
#include <string.h>
#define MAXN 102
int adj[MAXN][MAXN];
int indeg[MAXN];
int que[MAXN];
int ans[MAXN];
int head, tail;
int n;
void init()
{
	int i, j;
	scanf("%d", &n);
	memset(indeg, 0, sizeof(indeg));
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		while(1)
		{
			scanf("%d", &j);
			if(j == 0) break;
			adj[i][j] = 1;
			indeg[j]++;
		}
	}
}
void topsort()
{
	int i, j, k = 0;
	head = 0; tail = 0;
	for(i = 1;i <= n; i++) if(indeg[i] == 0) que[tail++] = i;
	while(head < tail)
	{
		i = que[head];
		ans[++k] = i;
		for(j = 1;j <= n; j++)
		{
			if(adj[i][j])
			{
				indeg[j]--;
				if(indeg[j] == 0) que[tail++] = j;
			}
		}
		head++;
	}
	j = 1;
	for(i = 1;i <= n; i++)
	{
		if(j) printf("%d", ans[i]);
		else printf(" %d", ans[i]);
		j = 0;
	}
	printf("\n");
}
int main()
{
	init();
	topsort();
	return 0;
}
