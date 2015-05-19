#include <stdio.h>
#include <string.h>
#define PARENT(i) ((i)>>1)
#define RIGHT(i) (((i)<<1)+1)
#define LEFT(i) (i<<1)
#define oo 0x7fffffff
#define MAXM 150002
#define MAXN 30002
typedef struct
{
	int u; int v; int w; int next;
}edge_t;
edge_t e[MAXM];
int heap[MAXN];
int first[MAXN];
int pos[MAXN];
int d[MAXN];
int tot, n;
void init_heap(){ heap[0] = 0; }
void min_heap(int i)
{
	int min;
	int tmp;
	int r = RIGHT(i);
	int l = LEFT(i);
	if(l <= heap[0] && d[heap[l]] < d[heap[i]]) min = l;
	else min = i;
	if(r <= heap[0] && d[heap[r]] < d[heap[min]]) min = r;
	if(min != i)
	{
		tmp = heap[i]; heap[i] = heap[min]; heap[min] = tmp;
		min_heap(min);
		pos[heap[i]] = i;
		pos[heap[min]] = min;
	}
}
int empty() { return heap[0] <= 0; }
int pop()
{
	int min = heap[1];
	heap[1] = heap[heap[0]];
	pos[heap[1]] = 1;
	heap[0]--;
	min_heap(1);
	return min;
}
void heap_up(int i)
{
	int tmp, j;
	while(i > 1 && d[heap[PARENT(i)]] > d[heap[i]])
	{
		tmp = heap[PARENT(i)];
		heap[PARENT(i)] = heap[i]; 
		heap[i] = tmp;
		pos[heap[PARENT(i)]] = PARENT(i);
		pos[heap[i]] = i;
		i = PARENT(i);
	}
}
void add(int u, int v, int w)
{
	e[++tot].u = u;  e[tot].v = v;  e[tot].w = w;  e[tot].next = first[u]; 
	first[u] = tot;
}
void dij()
{
	int i, j, t, k;
	init_heap();
	heap[++heap[0]] = 1;
	d[1] = 0; pos[1] = heap[0];
	for(i = 2;i <= n; i++) 
	{
		d[i] = oo;
		heap[++heap[0]] = i;
		pos[i] = heap[0];
	}
	for(k = 1;k <= n; k++)
	{
		i = pop();
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(d[j] > d[i] + e[t].w)
			{
				d[j] = d[i] + e[t].w;
				heap_up(pos[j]);
			}
			t = e[t].next;
		}
	}
	printf("%d\n", d[n]);
}
int main()
{
	int a, b, c, m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(first, -1, sizeof(first));
		tot = 0;
		while(m--)
		{
			scanf("%d %d %d", &a, &b, &c);
			add(a, b, c);
		}
		dij();
	}
	return 0;
}

