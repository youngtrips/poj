#include <stdio.h>
#include <string.h>
#define MAX 33
int adj[MAX * MAX][MAX * MAX], n;
int match[MAX * MAX], v[MAX * MAX];
int dx[4] = {0, 1,  0, -1};
int dy[4] = {1, 0, -1,  0};
int no[MAX][MAX], r, c;
char map[MAX][MAX];
int check(int x, int y) { return x >= 1 && x <= r && y >= 1 && y <= c && map[x][y] == '1';}
void init()
{
	int cnt, i, j, k, x, y;
	scanf("%d %d %d", &r, &c, &k);
	memset(map, '1', sizeof(map));
	while(k--)
	{
		scanf("%d %d", &i, &j);
		map[j][i] = '0';
	}
	memset(adj, 0, sizeof(adj));
	cnt = 1;
	for(i = 1;i <= r; i++)
		for(j = 1;j <= c; j++) if(map[i][j] == '1') no[i][j] = cnt++;
	n = cnt - 1;
	for(i = 1;i <= r; i++)
	{
		for(j = 1;j <= c; j++)
		{
			if(map[i][j] == '1')
			{
				x = no[i][j];
				for(k = 0;k < 4; k++)
				{
					if(check(i + dx[k], j + dy[k]))
					{
						y = no[i + dx[k]][j + dy[k]];
						adj[x][y] = 1;
					}
				}
			}
		}
	}
}
int find(int i)
{
	int j;
	for(j = 1;j <= n; j++)
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
	init();
	if(hungary() == n) printf("YES\n");
	else printf("NO\n");
	return 0;
}
