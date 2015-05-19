#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 120
#define MAXN 120
typedef struct
{
	int u; int v; int w;
}edge_t;
edge_t e[MAXM * MAXM];
int d[MAXN * MAXN];
int tot, n;
void add(int u, int v, int w)
{
	e[++tot].u = u; e[tot].v = v; e[tot].w = w;
}
int init()
{
	char oi[3];
	int si, ni, ki, i, m;
	scanf("%d", &n);
	if(n == 0) return 0;
	scanf("%d", &m);
	tot = 0;
	while(m--)
	{
		scanf("%d %d %s %d", &si, &ni, oi, &ki);
		ni = si + ni + 1;
		if(oi[0] == 'g') add(ni, si, -1 - ki);
		else add(si, ni, ki - 1);
	}
	n++;
	for(i = 1;i <= n; i++) add(0, i, 0);
	return 1;
}
void bellman_ford()
{
	int flag, i, j;
	for(i = 0;i <= n; i++) d[i] = oo;
	d[0] = 0;
	for(j = 1;j < n; j++)
	{
		flag = 1;
		for(i = 1;i <= tot; i++)
		{
			if(d[e[i].v] > d[e[i].u] + e[i].w)
			{
				d[e[i].v] = d[e[i].u] + e[i].w;
				flag = 0;
			}
		}
		if(flag) break;
	}
	printf("%s\n", flag == 0 ? "successful conspiracy" : "lamentable kingdom");
}
int main()
{
	while(init()) bellman_ford();
	return 0;
}
