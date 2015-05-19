#include <cstdio>
#include <queue>
#include <cstring>
#define oo 999999999
#define MAXM 10002
#define MAXN 102
using namespace std;
struct edge_t{int v; int l; int t; int next;};
struct state_t
{
	int s; int dist; int cost;
	friend bool operator < (state_t s1, state_t s2)
	{
		return s1.dist > s2.dist;
	}
};
edge_t e[MAXM];
int first[MAXN];
int dist, tot, k, n;
void add(int u, int v, int l, int t)
{
	e[++tot].v = v; e[tot].l = l; e[tot].t = t;
	e[tot].next = first[u]; first[u] = tot;
}
void init()
{
	int m, i, j, l, t;
	scanf("%d %d %d", &k, &n, &m);
	memset(first, -1, sizeof(first));
	tot = 0;
	while(m--)
	{
		scanf("%d %d %d %d", &i, &j, &l, &t);
		add(i, j, l, t);
	}
}
priority_queue < state_t> q;
void solve()
{
	int j, t;
	state_t tmp, cur;
	dist = oo;
	cur.s = 1; cur.dist = 0; cur.cost = 0;
	while(!q.empty()) q.pop();
	q.push(cur);
	while(!q.empty())
	{
		cur = q.top(); q.pop();
		if(cur.s == n) break;
		t = first[cur.s];
		while(t != -1)
		{
			j = e[t].v;
			if(cur.cost + e[t].t <= k)
			{
				tmp.s = j;
				tmp.dist = cur.dist + e[t].l;
				tmp.cost = cur.cost + e[t].t;
				if(j == n && dist > tmp.dist) dist = tmp.dist;
				q.push(tmp);
			}
			t = e[t].next;
		}
	}
	printf("%d\n", (dist == oo ? -1 : dist));
}
int main()
{
	init();
	solve();
	return 0;
}
