#include <stdio.h>
#include <string.h>
#define MAXM 50002
#define MAXN 5002
typedef struct
{
	int u;
	int v;
	int s;
	int next;
}edge_t;
edge_t e[MAXM * 2];
int backward[MAXN];
int forward[MAXN];
int first[MAXN];
int pos[MAXM][2];
int in[MAXN];
int tot;
int n, m;
void add(int u, int v, int s)
{
	e[++tot].u = u; e[tot].v = v; e[tot].s = s;
	e[tot].next = first[u]; first[u] = tot;
}
void init()
{
	int i, j, k;
	scanf("%d %d", &n, &m);
	memset(first, -1, sizeof(first));
	memset(in, 0, sizeof(in));
	tot = 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &j, &k);
		pos[i][0] = j;
		pos[i][1] = k;
		add(j, k, 1);
		add(k, j, 0);
		in[k]++;
	}
}
void solve()
{
	int ans, i, j, t;
	memset(backward, 0, sizeof(backward));
	memset(forward, 0, sizeof(forward));
	forward[n] = 1;
	for(i = n - 1;i >= 1; i--)
	{
		t = first[i];
		while(t != -1)
		{
			if(e[t].s == 1)
			{
				j = e[t].v;
				forward[i] += forward[j];
			}
			t = e[t].next;
		}
	}
	for(i = 1;i <= n; i++) if(in[i] == 0) backward[i] = 1;
	for(i = 1;i <= n; i++)
	{
		t = first[i];
		while(t != -1)
		{
			if(e[t].s == 0)
			{
				j = e[t].v;
				backward[i] += backward[j];
			}
			t = e[t].next;
		}
	}
	ans = 0;
	for(i = 1;i <= m; i++)
	{
		t = forward[pos[i][1]] * backward[pos[i][0]];
		if(ans < t) ans = t;
	}
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
