#include <stdio.h>
#include <string.h>
#define oo 99999999
#define MAX 102
int adj[MAX][MAX], n, st, ed;
int q[MAX], has[MAX], d[MAX], head, tail;
int pre[MAX];
void init()
{
	int i, j, k, m;
	scanf("%d %d %d", &n, &st, &ed);
	memset(adj, -1, sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &m);
		for(j = 0;j < m; j++)
		{
			scanf("%d", &k);
			adj[i][k] = j;
		}
	}
}
int spfa()
{
	int i, j, k;
	for(i = 1;i <= n; i++) d[i] = oo;
	memset(has, 0, sizeof(has));
	memset(pre, -1, sizeof(pre));
	d[st] = 0;
	has[st] = 1;
	q[0] = st;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		i = q[head];
		has[i] = 0;
		for(j = 1;j <= n; j++)
		{
			if(adj[i][j] != -1 && d[j] > d[i] + adj[i][j])
			{
				d[j] = d[i] + adj[i][j];
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
	return d[ed] != oo;
}
int main()
{
	int i;
	init();
	if(spfa() == 1) printf("%d\n", d[ed]);
	else printf("-1\n");
	return 0;
}
