#include <stdio.h>
#include <string.h>
#define oo 99999999
#define MAX 102
int adj[MAX][MAX], n;
int q[MAX], d[MAX], head, tail;
int init()
{
	int i, j, c, k;
	scanf("%d", &n);
	if(n == 0) return 0;
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &k);
		while(k--)
		{
			scanf("%d %d", &j, &c);
			adj[i][j] = c;
		}
	}
	return 1;
}
void spfa(int st)
{
	int i, j;
	for(i = 1;i <= n; i++) d[i] = oo;
	d[st] = 0;
	q[0] = st;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		i = q[head];
		for(j = 1;j <= n; j++)
		{
			if(adj[i][j] && d[j] > d[i] + adj[i][j])
			{
				d[j] = d[i] + adj[i][j];
				q[tail++] = j;
			}
		}
		head++;
	}
}
int main()
{
	int disjoin, flag, min, max, p, i, j;
	while(init())
	{
		disjoin = 1;
		min = oo;
		for(i = 1;i <= n; i++)
		{
			spfa(i);
			flag = 0;
			max = 0;
			for(j = 1;j <= n; j++)
			{
				if(max < d[j]) max = d[j];
				if(d[j] == oo) flag = 1;
			}
			if(min > max) { min = max; p = i;}
			disjoin &= flag;
		}
		if(disjoin) printf("disjoint\n");
		else printf("%d %d\n", p, min);
	}
	return 0;
}
