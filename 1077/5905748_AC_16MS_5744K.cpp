#include <stdio.h>
#include <string.h>
#define ABS(x) ((x)<0?-(x):(x))
#define _cp(a,b) ((a.f)<=(b.f))
#define MAXN 500002
struct node_t
{
	int stat[10];
	int k;
	int g;
	int f;
};
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
node_t start;
heap_t q;
char act[] = "drul";
int dir[4] = {3, 1, -3, -1};
int dist[10][10];
int mv[10][5] = {
				{0},
				{2, 0, 1},		/* 1 */
				{3, 0, 1, 3},	/* 2 */
				{2, 0, 3},		/* 3 */
				{3, 0, 1, 2},	/* 4 */
				{4, 0, 1, 2, 3},/* 5 */
				{3, 0, 2, 3},	/* 6 */
				{2, 1, 2},		/* 7 */
				{3, 1, 2, 3},	/* 8 */
				{2, 2, 3}		/* 9 */
				};
int f[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int pre[MAXN];
int has[MAXN];
int ans[MAXN];
int tmp[MAXN];
int hash(node_t cur)
{
	int res, i, j, k = 1;
	res = 0;
	for(i = 1;i <= 9; i++)
	{
		k = 0;
		for(j = 1;j < i; j++) if(cur.stat[i] < cur.stat[j]) k++;
		res += k * f[i-1];
	}
	return res;
}
int get_dist(int i, int j)
{
	int x1 = (i - 1) / 3 + 1;
	int y1 = (i - 1) % 3 + 1;
	int x2 = (j - 1) / 3 + 1;
	int y2 = (j - 1) % 3 + 1;
	return ABS(x1 - x2) + ABS(y1 - y2);
}
void init_dist()
{
	int i, j;
	for(i = 1;i <= 9; i++)
		for(j = 1;j <= 9; j++) dist[i][j] = get_dist(i, j);
}
int heur(node_t node)
{
	int sum = 0, i;
	for(i = 1;i <= 9; i++) sum += dist[i][node.stat[i]];
	return sum;
}
int is_solvable(node_t st)
{
	int res = 0, i, j;
	for(i = 1;i <= 9; i++)
		for(j = 1;j < i; j++) if(st.stat[i] < st.stat[j]) res++;
	res += dist[9][st.stat[0]];
	return (res & 1) == 0;
}
void init()
{
	char tmp[2];
	int i;
	for(i = 1;i <= 9; i++)
	{
		scanf("%s", tmp);
		if(tmp[0] == 'x')
		{
			start.stat[i] = 9;
			start.stat[0] = i;
		}
		else start.stat[i] = tmp[0] - '0';
	}
	start.g = 0;
	start.f = heur(start);
	start.k = hash(start);
}
void output()
{
	int i = 0, j = 0;
	while(pre[i] != -1)
	{
		ans[++j] = tmp[i];
		i = pre[i];
	}
	for(i = j;i > 1; i--) printf("%c", act[ans[i]]);
	printf("%c\n", act[ans[1]]);
}
void astar(node_t st)
{
	node_t cur, nxt;
	int g, i, j, k, p;
	memset(pre, -1, sizeof(pre));
	memset(has, -1, sizeof(has));
	q.init();
	q.push(st);
	has[st.k] = 0;
	while(!q.empty())
	{
		cur = q.pop();
		j = cur.stat[0];
		g = cur.g;
		for(i = 1;i <= mv[j][0]; i++)
		{
			nxt = cur;
			k = mv[j][i];
			p = j + dir[k];
			nxt.stat[j] = nxt.stat[p];
			nxt.stat[p] = 9;
			nxt.stat[0] = p;
			nxt.g = g + 1;
			nxt.f = nxt.g + heur(nxt);
			nxt.k = hash(nxt);
			if(has[nxt.k] == -1)
			{
				tmp[nxt.k] = k;
				has[nxt.k] = 0;
				pre[nxt.k] = cur.k;
				q.push(nxt);
			}
			if(nxt.k == 0) return;
		}
	}
}
int main()
{
	int t;
	init_dist();
	init();
	if(is_solvable(start) == 0)
	{
		printf("unsolvable\n");
		return 0;
	}
	if(start.k == 0)
	{
		printf("lr\n");
		return 0;
	}
	astar(start);
	output();;
	return 0;
}
