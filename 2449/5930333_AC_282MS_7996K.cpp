#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 200002
#define MAXN 400002
#define MAXV 1002
#define _cp(a,b) ((a.f)<=(b.f))
typedef struct { int v; int w; char f; int next; }edge_t;
typedef struct { int u; int g; int f; }node_t;
typedef node_t elem_t;
struct heap_t
{
    elem_t heap[MAXN];
    int top;
    heap_t() { top = 0;}
	void init() { top = 0;}
    int empty() { return top <= 0; }
    void filterdown(int start, int end)
    {
        int i = start, j = (i<<1) + 1;
        elem_t tmp = heap[i];
        while(j <= end)
        {
            if(j < end && !_cp(heap[j], heap[j + 1])) j++;
            if(_cp(tmp, heap[j])) break;
            else
            {
                heap[i] = heap[j];
                i = j; j = (j<<1) + 1;
            }
        }
        heap[i] = tmp;
    }
    void filterup(int start)
    {
        int j = start, i = (j - 1)>>1;
        elem_t tmp = heap[j];
        while(j > 0)
        {
            if(_cp(heap[i], tmp)) break;
            else
            {
                heap[j] = heap[i];
                j = i; i = (i - 1)>>1;
            }
        }
        heap[j] = tmp;
    }
    elem_t pop()
    {
        elem_t i = heap[0];
        heap[0] = heap[(top--) - 1];
        filterdown(0, top - 1);
        return i;
    }
    void push(elem_t a)
    {
        heap[top++] = a;
        filterup(top - 1);
    }
};
edge_t e[MAXM];
heap_t q;
int first[MAXV];
int dist[MAXV];
int cnt[MAXV];
int tot, st, ed;
int n, m, k;
void add(int u, int v, int w)
{
	e[++tot].v = v; e[tot].w = w; e[tot].f = 1; e[tot].next = first[u]; first[u] = tot;
	e[++tot].v = u; e[tot].w = w; e[tot].f = 0; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int u, v, w;
	scanf("%d %d", &n, &m);
	memset(first, -1, sizeof(first));
	tot = -1;
	while(m--)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	scanf("%d %d %d", &st, &ed, &k);
	if(st == ed) k++;
}
void dij()
{
	node_t cur;
	node_t nxt;
	int i, j, t;
	for(i = 1;i <= n; i++) dist[i] = oo;
	memset(cnt, 0, sizeof(cnt));
	dist[ed] = 0;
	cur.u = ed; cur.f = 0;
	q.init(); q.push(cur);
	while(!q.empty())
	{
		cur = q.pop();
		if(cnt[cur.u]) continue;
		cnt[cur.u] = 1;
		for(t = first[i=cur.u];t != -1; t = e[t].next)
		{
			j = e[t].v;
			if(e[t].f == 0 && cnt[j] == 0 && dist[j] > dist[i] + e[t].w)
			{
				dist[j] = dist[i] + e[t].w;
				nxt.u = j;
				nxt.f = dist[j];
				q.push(nxt);
			}
		}
	}
}
int astar()
{
	node_t cur;
	node_t nxt;
	int i, j, t;
	if(dist[st] == oo) return -1;
	memset(cnt, 0, sizeof(cnt));
	cur.u = st; cur.g = 0; cur.f = dist[st];
	q.init(); q.push(cur);
	while(!q.empty())
	{
		cur = q.pop();
		cnt[cur.u]++;
		if(cnt[ed] == k) return cur.g;
		if(cnt[cur.u] > k) continue;
		for(t = first[i=cur.u];t != -1; t = e[t].next)
		{
			if(e[t].f)
			{
				j = e[t].v;
				nxt.u = j;
				nxt.g = cur.g + e[t].w;
				nxt.f = nxt.g + dist[j];
				q.push(nxt);
			}
		}
	}
	return -1;
}
int main()
{
	int res;
	init();
	dij();
	res = astar();
	printf("%d\n", res);
    return 0;
}
