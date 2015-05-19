#include <stdio.h>
#include <string.h>
#define MAX 502
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
	int r, c, k;
	scanf("%d %d", &n, &k);
	memset(adj, 0, sizeof(adj));
	while(k--)
	{
		scanf("%d %d", &r, &c);
		adj[r][c] = 1;
	}
	printf("%d\n", hungary());
	return 0;
}
