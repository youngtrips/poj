#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 102
#define MAXN 102
typedef struct
{
	int u; int v; int w;
}edge_t;
edge_t e[MAXM * MAXM];
int d[MAXN * MAXN];
int tot, st, ed, n;
void add(int u, int v, int w)
{
	e[++tot].u = u; e[tot].v = v; e[tot].w;
}
int init()
{
	char oi[3];
	int m, si, ni, ki;
	scanf("%d", &n);
	if(n == 0) return 0;
	scanf("%d", &m);
	st = 99999999; ed = -1;
	tot = 0;
	while(m--)
	{
		scanf("%d %d %s %d", &si, &ni, oi, &ki);
		si; ni = si + ni + 1;
		if(st > si) st = si;
		if(st > ni) st = ni;
		if(ed < si) ed = si;
		if(ed < ni) ed = ni;
		if(oi[0] == 'g') add(ni, si, -ki - 1);
		else add(si, ni, ki - 1);
	}
	return 1;
}
void bellman_ford()
{
	int flag, i, j;
	for(i = st;i <= ed; i++) d[i] = oo;
	d[st] = 0;
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
