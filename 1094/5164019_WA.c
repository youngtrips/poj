#include <stdio.h>
#include <string.h>
#define CLS(x) memset(x,0,sizeof(x))
#define MAX 27
int adj[MAX][MAX], order[MAX];
int cnt, n, m;
int topsort()
{
	int indeg[MAX];
	int top = -1, i, j, k;
	CLS(indeg);
	cnt = 0;
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) indeg[i] += adj[j][i];
	for(i = 1;i <= n; i++)
		if(indeg[i] == 0)
		{
			indeg[i] = top;
			top = i;
			cnt++;
		}
	for(i = 1;i <= n; i++)
	{
		if(top == -1) return 0;
		k = top;
		top = indeg[top];
		order[i] = k;
		for(j = 1;j <= n; j++)
		{
			if(adj[k][j]) indeg[j]--;
			if(indeg[j] == 0)
			{
				indeg[j] = top;
				top = j;
			}
		}
	}
	return 1;
}
int main()
{
	char str[4];
	int flag, res, i, j;
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		CLS(adj);
		flag = 0;
		for(i = 1;i <= m; i++)
		{
			scanf("%s", str);
			adj[str[0] - 'A' + 1][str[2] - 'A' + 1] = 1;
			if(flag == 0)
			{
				res = topsort();
				if(res == 0)
				{
					printf("Inconsistency found after %d relations.\n", i);
					flag = 1;
				}
				else
				{
					if(cnt == 1)
					{
						printf("Sorted sequence determined after %d relations: ", i);
						for(j = 1;j <= n; j++) printf("%c", order[j] - 1 + 'A');
						printf("\n");
						flag = 1;
					}
				}
			}
		}
		if(flag == 0) printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}
