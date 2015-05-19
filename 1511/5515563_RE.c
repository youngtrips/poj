#include <stdio.h>
#include <string.h>
#define oo 1000000000
#define MAX 1000002
typedef struct
{
	int u;
	int v;
	int w;
	int f;
	int next;
}edge_t;
edge_t e[MAX * 2];
int first[MAX];
int has[MAX];
int d[MAX];
int q[MAX * 2];
int head, tail;
int tot;
int n;
void add(int u, int v, int w, int f)
{
	e[++tot].u = u; e[tot].v = v; e[tot].w = w; e[tot].f = f; 
	e[tot].next = first[u];
	first[u] = tot;
}
void init()
{
	int m, i, j, k;
	memset(first, -1, sizeof(first));
	tot = 0;
	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &k);
		add(i, j, k, 1);
		add(j, i, k, 0);
	}
}
void spfa(int flag)
{
	int i, j, t;
	memset(has, 0, sizeof(has));
	for(i = 1;i <= n; i++) d[i] = oo;
	has[1] = 1;
	q[0] = 1;
	d[1] = 0;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		i = q[head];
		has[i] = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].f == flag && d[i] + e[t].w < d[j])
			{
				d[j] = d[i] + e[t].w;
				if(has[j] == 0)
				{
					has[j] = 1;
					q[tail++] = j;
				}
			}
			t = e[t].next;
		}
		head++;
	}
}
void solve()
{
	long long ans;
	int i;
	ans = 0;
	spfa(1);
	for(i = 2;i <= n; i++) ans += d[i];
	spfa(0);
	for(i = 2;i <= n; i++) ans += d[i];
	printf("%lld\n", ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}
