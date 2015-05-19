#include <stdio.h>
#include <string.h>
#define PARENT(i) ((i)>>1)
#define RIGHT(i) (((i)<<1)+1)
#define LEFT(i) (i<<1)
#define MAXN 102
typedef struct { int val[MAXN]; int tot;}heap_t;
typedef struct { int u; int v; int next;}edge_t;
heap_t heap;
edge_t e[MAXN];
int first[MAXN];
int deg[MAXN];
int has[MAXN];
int ans[MAXN];
int tot, cnt, n;
void init_heap(heap_t* heap){ heap->tot = 0; }
void min_heap(heap_t* heap, int i)
{
	int min;
	int tmp;
	int r = RIGHT(i);
	int l = LEFT(i);
	if(l <= heap->tot && heap->val[l] < heap->val[i]) min = l;
	else min = i;
	if(r <= heap->tot && heap->val[r] < heap->val[min]) min = r;
	if(min != i)
	{
		tmp = heap->val[i]; heap->val[i] = heap->val[min]; heap->val[min] = tmp;
		min_heap(heap, min);
	}
}
int empty(heap_t heap) { return heap.tot <= 0; }
int pop(heap_t* heap)
{
	int min = heap->val[1];
	heap->val[1] = heap->val[heap->tot];
	heap->tot--;
	min_heap(heap, 1);
	return min;
}
void push(heap_t* heap, int x)
{
	int tmp, i, j;
	heap->val[++heap->tot] = x;
	i = heap->tot;
	while(i > 1 && heap->val[PARENT(i)] > heap->val[i])
	{
		tmp = heap->val[PARENT(i)];
		heap->val[PARENT(i)] = heap->val[i]; 
		heap->val[i] = tmp;
		i = PARENT(i);
	}
}

void add(int u, int v)
{
	e[++tot].u = u; e[tot].v = v; e[tot].next = first[u]; first[u] = tot;
}
void parse(int p)
{
	char ch;
	int x;
	scanf("%d", &x);
	if(p)
	{
		if(n < p) n = p;
		if(n < x) n = x;
		add(p, x);
		add(x, p);
		deg[x]++; deg[p]++;
	}
	while(1)
	{
		ch = getchar();
		if(ch == ')') break;
		if(ch == '(') parse(x);
	}
}
void init()
{
	init_heap(&heap);
	memset(first, -1, sizeof(first));
	memset(deg, 0, sizeof(deg));
	tot = 0; cnt = 0; n = 1;
}
void solve()
{
	int i, j, t;
	if(n == 1)
	{
		printf("\n");
		return;
	}
	for(i = 1;i <= n; i++) if(deg[i] == 1) push(&heap, i);
	memset(has, 0, sizeof(has));
	while(empty(heap) == 0)
	{
		i = pop(&heap);
		has[i] = 1;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(has[j] == 0)
			{
				ans[++cnt] = j;
				deg[j]--;
				if(deg[j] == 1) push(&heap, j);
			}
			t = e[t].next;
		}
	}
	for(i = 1;i < cnt; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[i]);
}
int main()
{
	char ch;
	int p;
	while(1)
	{
		ch = getchar();
		while(ch != '(' && ch != EOF) ch = getchar();
		if(ch == EOF) break;
		init();
		parse(0);
		solve();
		ch = getchar();
		while(ch != '\n' && ch != EOF) ch = getchar();
	}
	return 0;
}
