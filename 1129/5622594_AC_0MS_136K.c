#include <stdio.h>
#include <string.h>
#define MAXN 28
int color[MAXN];
int adj[MAXN][MAXN];
int n;
int init()
{
	char ch;
	int i, j;
	scanf("%d", &n);
	getchar();
	if(n == 0) return 0;
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		ch = getchar();
		while(ch != ':') ch = getchar();
		while(ch != '\n')
		{
			if(ch >= 'A' && ch <= 'Z')
			{
				adj[i][ch - 'A' + 1] = 1;
				adj[ch - 'A' + 1][i] = 1;
			}
			ch = getchar();
		}
	}
	return 1;
}

int check(int k)
{
	int j;
	for(j = 1;j <= n; j++) if(adj[k][j] == 1 && color[j] == color[k]) return 0;
	return 1;
}
int dfs(int t, int cols)
{
	int i;
	if(t > n) return 1;
	else
	{
		for(i = 1;i <= cols; i++)
		{
			color[t] = i;
			if(check(t)) return dfs(t + 1, cols);
			color[t] = 0;
		}
	}
	return 0;
}
int main()
{
	int i;
	while(init())
	{
		for(i = 1;i <= 4; i++)
		{
			memset(color, 0, sizeof(color));
			if(dfs(1, i)) break;
		}
		if(i == 1) printf("%d channel needed.\n", i);
		else printf("%d channels needed.\n", i);
	}
	return 0;
}
