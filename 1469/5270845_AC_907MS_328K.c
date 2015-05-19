#include <stdio.h>
#include <string.h>
#define MAXM 102
#define MAXN 302
int adj[MAXN][MAXM], n, m;
int match[MAXN], v[MAXN];
void init()
{
	int i, j, k;
	memset(adj, 0, sizeof(adj));
	scanf("%d %d", &m, &n);
	for(j = 1;j <= m; j++)
	{
		scanf("%d", &k);
		while(k--)
		{
			scanf("%d", &i);
			adj[i][j] = 1;
		}
	}
}

int findpath(int i)
{
	int j;
	for(j = 1;j <= m; j++)
	{
		if(adj[i][j] && v[j] == 0)
		{
			v[j] = 1;
			if(match[j] == -1 || findpath(match[j]))
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
		cnt += findpath(i);
	}
	return cnt;
}
int main()
{
	int res, t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		if(hungary() == m) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
