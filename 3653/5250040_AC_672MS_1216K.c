#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXN 450
int adj[MAXN][MAXN], n;
int d[MAXN];
int init()
{
	char s[2];
	int c, h, w, i, j, k, u1, v1, u2, v2, t1, t2;
	scanf("%d %d", &h, &w);
	if(h == 0 && w == 0) return 0;
	n = (h + 1) * (w + 1);
	for(i = 1;i <= n; i++) d[i] = oo;
	memset(adj, 0, sizeof(adj));
	t1 = 1; t2 = 1;
	for(i = 1;i <= (h * 2 + 1); i++)
	{
		if(i % 2 == 1) 
		{
			u1 = t1;
			v1 = u1 + 1;
			t1 += w + 1;
			k = w;
		}
		else 
		{
			u2 = t2;
			v2 = u2 + w + 1;
			t2 += w + 1;
			k = w + 1;
		}
		for(j = 1;j <= k; j++)
		{
			scanf("%d %s", &c, s);
			if(c != 0) c = 2520 / c;
			if(i % 2 == 1)
			{
				if(s[0] == '*') adj[u1][v1] = adj[v1][u1] = c;
				if(s[0] == '>') adj[u1][v1] = c;
				if(s[0] == '<') adj[v1][u1] = c;
				u1++; v1++;
			}
			else
			{
				if(s[0] == '*') adj[u2][v2] = adj[v2][u2] = c;
				if(s[0] == 'v') adj[u2][v2] = c;
				if(s[0] == '^') adj[v2][u2] = c;
				u2++; v2++;
			}
		}
	}
}
void bellman_ford()
{
	int i, j, k;
	d[1] = 0;
	for(k = 1;k < n; k++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++)
				if(d[i] < oo && adj[i][j] > 0 && d[j] > d[i] + adj[i][j]) d[j] = d[i] + adj[i][j];
}
int main()
{
	while(init())
	{
		bellman_ford();
		if(d[n] == oo) printf("Holiday\n");
		else printf("%d blips\n", d[n]);
	}
	return 0;
}
