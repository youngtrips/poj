#include <stdio.h>
#include <string.h>
#define MAXM 40002
#define MAXN 210
typedef struct{int u; int v; int f; int op; int next;}edge_t;
edge_t e[MAXM * 4];
int x[MAXM];
int y[MAXM];
int l[MAXM];
int first[MAXN];
int q[MAXN];
int pre[MAXN];
int head, tail;
int high, low, tot, st, ed, n, p, t;
void add(int u, int v, int f)
{
	++tot;
	e[tot].u = u; e[tot].v = v; e[tot].f = f;
	e[tot].next = first[u]; e[tot].op = tot + 1; first[u] = tot;
	++tot;
	e[tot].u = v; e[tot].v = u; e[tot].f = 0;
	e[tot].next = first[v]; e[tot].op = tot - 1; first[v] = tot;
}
void init()
{
	int i;
	scanf("%d %d %d", &n, &p, &t);
	low = 999999999; high = 0;
	for(i = 1;i <= p; i++)
	{
		scanf("%d %d %d", &x[i], &y[i], &l[i]);
		if(low > l[i]) low = l[i];
		if(high < l[i]) high = l[i];
	}
	st = 1; ed = n;
}
void build(int max)
{
	int i;
	memset(first, -1, sizeof(first));
	tot = 0;
	for(i = 1;i <= p; i++) 
	{
		if(l[i] <= max)
		{
			add(x[i], y[i], 1);
			add(y[i], x[i], 1);
		}
	}
}
int bfs()
{
	int i, j, t;
	memset(pre, -1, sizeof(pre));
	q[0] = st; head = 0; tail = 1;
	pre[st] = -2;
	while(head < tail)
	{
		i = q[head];
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].f > 0 && pre[j] == -1)
			{
				pre[j] = t;
				if(j == ed) return 1;
				q[tail++] = j;
			}
			t = e[t].next;
		}
		head++;
	}
	return 0;
}
int ford()
{
	int max = 0, i, t;
	while(bfs())
	{
		i = ed;
		while(i != st)
		{
			t = pre[i];
			e[t].f--;
			e[e[t].op].f++;
			i = e[t].u;
		}
		max++;
	}
	return max;
}
int main()
{
	int mid, res;
	init();
	while(low < high)
	{
		mid = (low + high)>>1;
		build(mid);
		res = ford();
		if(res >= t) high = mid;
		else low = mid + 1;
	}
	printf("%d\n", low);
	return 0;
}
