#include <stdio.h>
#include <string.h>
#define ABS(x) ((x)<0?(-(x)):(x))
#define PARENT(i) ((i)>>1)
#define RIGHT(i) (((i)<<1)+1)
#define LEFT(i) (i<<1)
#define MAXN 50002
typedef struct
{
	int p;
	int x;
}node_t;
typedef struct
{
	node_t val[MAXN];
	int tot;
}heap_t;
heap_t heap;
int t, n;
void init_heap(){ heap.tot = 0; }
void min_heap(int i)
{
	node_t tmp;
	int min;
	int r = RIGHT(i);
	int l = LEFT(i);
	if(l <= heap.tot && heap.val[l].p < heap.val[i].p) min = l;
	else min = i;
	if(r <= heap.tot && heap.val[r].p < heap.val[min].p) min = r;
	if(min != i)
	{
		tmp = heap.val[i]; heap.val[i] = heap.val[min]; heap.val[min] = tmp;
		min_heap(min);
	}
}
int empty() { return heap.tot <= 0; }
node_t pop()
{
	node_t min = heap.val[1];
	heap.val[1] = heap.val[heap.tot];
	heap.tot--;
	min_heap(1);
	return min;
}
void push(node_t x)
{
	node_t tmp;
	int i, j;
	heap.val[++heap.tot] = x;
	i = heap.tot;
	while(i > 1 && heap.val[PARENT(i)].p > heap.val[i].p)
	{
		tmp = heap.val[PARENT(i)];
		heap.val[PARENT(i)] = heap.val[i]; 
		heap.val[i] = tmp;
		i = PARENT(i);
	}
}
void init()
{
	node_t e;
	scanf("%d %d", &t, &n);
	init_heap();
	while(n--)
	{
		scanf("%d", &e.x);
		e.p = ABS(e.x); 
		push(e);
	}
}
void solve()
{
	node_t e;
	int ans = 0, pre = 0;
	while(!empty())
	{
		e = pop();
		t -= ABS(e.x - pre);
		if(t < 0) break;
		pre = e.x;
		ans++;
	}
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
