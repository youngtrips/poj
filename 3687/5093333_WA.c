#include <stdio.h>
#include <memory.h>
#define MAX 201
#define CLS(x) memset(x, 0, sizeof(x))
int adj[MAX][MAX];
void toposort(int n)
{
	int stack[MAX];
	int indeg[MAX];
	int r[MAX];
	int top = -1;
	int cnt = 0;
	int i, j, k;
	CLS(indeg);
	for(i = n;i >= 1; i--)
	{
		for(j = 1;j <= n; j++) indeg[i] += adj[j][i];
		if(indeg[i] == 0) stack[++top] = i;
	}
	while(top > -1)
	{
		k = stack[top--];
		r[cnt++] = k;
		for(i = n;i >= 1; i--)
		{
			if(adj[k][i] == 1)
			{
				indeg[i]--;
				if(indeg[i] == 0) stack[++top] = i;
			}
		}
	}
	if(cnt < n) printf("-1\n");
	else
	{
		for(i = 0;i < cnt - 1; i++) printf("%d ", r[i]);
		printf("%d\n", r[i]);
	}
}

int main()
{
	int t, n, m, i, j;
	scanf("%d", &t);
	while(t--)
	{
		CLS(adj);
		scanf("%d %d", &n, &m);
		while(m--)
		{
			scanf("%d %d", &i, &j);
			adj[i][j] = 1;
		}
		toposort(n);
	}
	return 0;
}
