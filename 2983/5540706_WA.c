#include <stdio.h>
#include <string.h>
#define MAXM 100002
#define MAXN 1002
#define oo 2100000000
typedef struct
{
	int u; int v; int w;
}edge_t;
edge_t e[MAXM * 10];
int d[MAXN];
int tot, n;
void add(int u, int v, int w)
{
	e[++tot].u = u; e[tot].v = v; e[tot].w = w;
}
void bellman_ford()
{
	int flag, i, k;
	for(i = 1;i <= n; i++) d[i] = oo;
	d[1] = 0;
	for(k = 1;k <= n; k++)
	{
		flag = 1;
		for(i = 1;i <= tot; i++)
		{
			if(d[e[i].u] != oo && d[e[i].v] > d[e[i].u] + e[i].w)
			{
				d[e[i].v] = d[e[i].u] + e[i].w;
				flag = 0;
			}
		}
		if(flag) break;
	}
	printf("%s\n", flag == 1 ? "Reliable" : "Unreliable");
}
int main()
{
	char ch[5];
	int i, a, b, x, m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		tot = 0;
		while(m--)
		{
			scanf("%s", ch);
			if(!strcmp(ch, "P"))
			{
				scanf("%d %d %d", &a, &b, &x);
				add(b, a, x);
				add(a, b, -x);
			}
			else
			{
				scanf("%d %d", &a, &b);
				add(a, b, -1);
			}
		}
		bellman_ford();
	}
	return 0;
}
