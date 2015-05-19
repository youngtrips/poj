#include <stdio.h>
#include <string.h>
#define MAX 338
int adj[MAX][MAX], cur, n;
char str[MAX][20];
int q[MAX], indeg[MAX], head, tail;
int insert(char* elem)
{
	int i;
	for(i = 1;i < cur; i++) if(!strcmp(str[i], elem)) return i;
	strcpy(str[cur], elem);
	return cur++;
}
void init()
{
	int i, j, k;
	char a[20], b[20];
	scanf("%d", &n);
	cur = 1;
	memset(adj, 0, sizeof(adj));
	memset(indeg, 0, sizeof(indeg));
	for(k = 1;k < n; k++)
	{
		scanf("%s %s", &a, &b);
		i = insert(a);
		j = insert(b);
		adj[i][j] = 1;
	}
}
void topsort()
{
	int i, j, k;
	head = 0;
	tail = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++) indeg[i] += adj[j][i];
		if(indeg[i] == 0) q[tail++] = i;
	}
	while(head < tail)
	{
		k = q[head];
		printf("%s\n", str[k]);
		for(i = 1;i <= n; i++)
		{
			if(adj[k][i] == 1)
			{
				indeg[i]--;
				if(indeg[i] == 0) q[tail++] = i;
			}
		}
		head++;
	}
}
int main()
{
	int s, t;
	scanf("%d", &t);
	for(s = 1;s <= t; s++)
	{
		init();
		printf("Scenario #%d:\n", s);
		topsort();
		printf("\n");
	}
	return 0;
}
