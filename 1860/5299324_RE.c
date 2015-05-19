#include <stdio.h>
#include <string.h>
#define eps 1e-20
#define MAX 102
char ans[2][4] = {"NO", "YES"};
typedef struct
{
	int u;
	int v;
	double r;
	double c;
}edge_t;
edge_t e[MAX];
double d[MAX], cur;
int tot, n, s; 
void init()
{
	double r, c;
	int m, i, j;
	scanf("%d %d %d %lf", &n, &m, &s, &cur);
	tot = 0;
	while(m--)
	{
		scanf("%d %d", &i, &j);
		scanf("%lf %lf", &r, &c);
		e[tot].u = i;
		e[tot].v = j;
		e[tot].r = r;
		e[tot].c = c;
		tot++;
		scanf("%lf %lf", &r, &c);
		e[tot].u = j;
		e[tot].v = i;
		e[tot].r = r;
		e[tot].c = c;
		tot++;
	}
}
int bellman_ford()
{
	int flag, i, u, v;
	for(i = 1;i <= n; i++) d[i] = 0.0;
	d[s] = cur;
	while(1)
	{
		flag = 1;
		for(i = 0;i < tot; i++)
		{
			u = e[i].u; v = e[i].v;
			if(d[v] + eps < (d[u] - e[i].c) * e[i].r)
			{
				flag = 0;
				d[v] = (d[u] - e[i].c) * e[i].r;
			}
		}
		if(cur + eps < d[s]) return 1;
		if(flag) break;
	}
	if(cur + eps < d[s]) return 1;
	return 0;
}
int main()
{
	int i, res;
	init();
	res = bellman_ford();
	printf("%s\n", ans[res]);
	return 0;
}
