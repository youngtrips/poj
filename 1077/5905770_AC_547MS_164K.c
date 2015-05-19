#include <stdio.h>
#include <string.h>
#define ABS(x) ((x)<0?-(x):(x))
typedef struct
{
	int stat[10];
	int x;
}node_t;
node_t st;
int stack[1000002];
int dist[10][10];
/*
 *	d --  0
 *	r --- 1
 *	u --- 2
 *	l --- 3
 */
char act[] = "drul";
int dir[4] = {3, 1, -3, -1};
int mv[10][5] = {{0},
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
int found, top, min;
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
	res += dist[9][st.x];
	return (res & 1) == 0;
}
int init()
{
	char str[2];
	int i;
	for(i = 1;i <= 9; i++)
	{
		if(scanf("%s", str) == EOF) return 0;
		if(str[0] == 'x')
		{
			st.stat[i] = 9;
			st.x = i;
		}
		else st.stat[i] = str[0] - '0';
	}
	return 1;
}
void output()
{
	int i;
	for(i = 1;i <= top; i++) printf("%c", act[stack[i]]);
	printf("\n");
}
void dfs(int p, int dp, int maxdp)
{
	int f = heur(st);
	int i, k, t;
	if(min > f) min = f;
	if(f + dp > maxdp || found) return;
	if(f == 0)
	{
		output();
		found = 1;
		return;
	}
	for(i = 1;i <= mv[p][0]; i++)
	{
		k = mv[p][i];
		t = dir[k] + p;
		st.stat[p] = st.stat[t];
		st.stat[t] = 9;
		stack[++top] = k;
		dfs(t, dp + 1, maxdp);
		top--;
		st.stat[t] = st.stat[p];
		st.stat[p] = 9;
	}
}
void ida_star(node_t st)
{
	int maxdp = heur(st);
	found = 0;
	while(found == 0)
	{
		min = 0x7fffffff;
		top = 0;
		dfs(st.x, 0, maxdp);
		maxdp += min;
	}
}
int main()
{
	init_dist();
	while(init())
	{
		if(is_solvable(st) == 0)
		{
			printf("unsolvable\n");
			continue;
		}
		ida_star(st);
	}
	return 0;
}
