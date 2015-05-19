#include <stdio.h>
#include <string.h>
#define PARENT(i) ((i)>>1)
#define RIGHT(i) (((i)<<1)+1)
#define LEFT(i) (i<<1)
#define MAXN 20012
#define MAXM 302
typedef struct
{
	int x;
	int y;
	int val;
}node_t;
typedef struct
{
	node_t h[MAXN];
	int size;
}heap_t;
heap_t heap;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[MAXM][MAXM];
int q[MAXM * MAXM][2];
int map[MAXM][MAXM];
int head, tail, w, h;
long long ans;
void init_heap(){ heap.size = 0; }
void min_heap(int i)
{
	node_t tmp;
	int min;
	int r = RIGHT(i);
	int l = LEFT(i);
	if(l <= heap.size && heap.h[l].val < heap.h[i].val) min = l;
	else min = i;
	if(r <= heap.size && heap.h[r].val < heap.h[min].val) min = r;
	if(min != i)
	{
		tmp = heap.h[i]; heap.h[i] = heap.h[min]; heap.h[min] = tmp;
		min_heap(min);
	}
}
int empty() { return heap.size <= 0; }
node_t pop()
{
	node_t min = heap.h[1];
	heap.h[1] = heap.h[heap.size];
	heap.size--;
	min_heap(1);
	return min;
}
void push(node_t x)
{
	node_t tmp;
	int i, j;
	visited[x.x][x.y] = 1;
	heap.h[++heap.size] = x;
	i = heap.size;
	while(i > 1 && heap.h[PARENT(i)].val > heap.h[i].val)
	{
		tmp = heap.h[PARENT(i)];
		heap.h[PARENT(i)] = heap.h[i]; 
		heap.h[i] = tmp;
		i = PARENT(i);
	}
}
void init()
{
	node_t e;
	int i, j;
	init_heap();
	memset(visited, 0, sizeof(visited));
	scanf("%d %d", &w, &h);
	for(i = 1;i <= h; i++)
	{
		for(j = 1;j <= w; j++)
		{
			scanf("%d", &map[i][j]);
			if(i == 1 || i == h || j == 1 || j == w)
			{
				e.val = map[i][j]; e.x = i; e.y = j;
				push(e);
			}
		}
	}
}
void floodfill(node_t st)
{
	node_t e;
	int tx, ty, x, y, i, j;
	q[0][0] = st.x; q[0][1] = st.y;
	head = 0; tail = 1;
	while(head < tail)
	{
		x = q[head][0]; y = q[head][1];
		for(i = 0;i < 4; i++)
		{
			tx = x + dx[i]; ty = y + dy[i];
			if(tx >= 1 && tx <= h && ty >= 1 && ty <= w && visited[tx][ty] == 0)
			{
				visited[tx][ty] = 1;
				if(map[tx][ty] > st.val)
				{
					e.val = map[tx][ty];
					e.x = tx;
					e.y = ty;
					push(e);
				}
				else
				{
					ans += st.val - map[tx][ty];
					q[tail][0] = tx;
					q[tail][1] = ty;
					tail++;
				}
			}
		}
		head++;
	}
}
void solve()
{
	ans = 0;
	while(!empty()) floodfill(pop());
	printf("%lld\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
