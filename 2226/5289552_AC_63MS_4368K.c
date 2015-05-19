#include <stdio.h>
#include <string.h>
#define MAX 1000
char map[51][51];
int mark1[51][51];
int mark2[51][51];
int adj[MAX][MAX], n, m;
int match[MAX], v[MAX];
void init()
{
	int flag, i, j, p, tn, tm;
	scanf("%d %d", &n, &m);
	getchar();
	memset(mark1, -1, sizeof(mark1));
	memset(mark2, -1, sizeof(mark2));
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++) map[i][j] = getchar();
		getchar();
	}
	p = 1;
	for(i = 1;i <= n; i++)
	{
		j = 1;
		while(1)
		{
			flag = 0;
			while(map[i][j] == '*')
			{
				mark1[i][j] = p;
				j++;
				flag = 1;
			}
			p += flag;
			j++;
			if(j > m) break;
		}
	}
	tn = p - 1;
	p = 1;
	for(j = 1;j <= m; j++)
	{
		i = 1;
		while(1)
		{
			flag = 0;
			while(map[i][j] == '*')
			{
				mark2[i][j] = p;
				i++;
				flag = 1;
			}
			p += flag;
			i++;
			if(i > n) break;
		}
	}
	tm = p - 1;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			if(mark1[i][j] != -1 && mark2[i][j] != -1)
				adj[mark1[i][j]][mark2[i][j]] = 1;
		}
	}
	n = tn; m = tm;
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
