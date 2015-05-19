#include <stdio.h>
#include <string.h>
#define MAX 122
int adj[MAX][MAX], n;
int match[MAX], v[MAX];
int find(int i)
{
	int j;
	for(j = 1;j <= n; j++)
		if(adj[i][j] && v[j] == 0)
		{
			v[j] = 1;
			if(match[j] == -1 || find(match[j]))
			{
				match[j] = i;
				return 1;
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
	int t, m, i, j;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		memset(adj, 0, sizeof(adj));
		while(m--)
		{
			scanf("%d %d", &i, &j);
			adj[i][j] = 1;
		}
		printf("%d\n", n - hungary());
	}
	return 0;
}
