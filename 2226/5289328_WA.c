#include <stdio.h>
#include <string.h>
#define MAX 52
int adj[MAX][MAX], n, m;
int match[MAX], v[MAX];
void init()
{
	int i, j;
	scanf("%d %d", &n, &m);
	getchar();
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			if(getchar() == '*') adj[i][j] = 1;
		}
		getchar();
	}
}
int find(int i)
{
	int j;
	for(j = 1;j <= m; j++)
	{
		if(adj[i][j] && v[j] == 0)
		{
			v[j] = 1;
			if(match[j] == -1 || find(match[j]))
			{
				match[j] = i;
				return 1;
			}
		}
	}
	return 0;
}
int hungary()
{
	int cnt = 0, i;
	memset(match, -1, sizeof(match));
	for(i = 1;i <= n; i++)
	{
		memset(v, 0, sizeof(v));
		cnt += find(i);
	}
	return cnt;
}
int main()
{
	int res;
	init();
	res = hungary();
	printf("%d\n", res);
	return 0;
}
