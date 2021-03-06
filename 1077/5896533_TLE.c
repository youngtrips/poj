#include <stdio.h>
#include <string.h>
#define ABS(x) ((x)<0?-(x):(x))

int goal[9][2] = {{1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}};
int f[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int max_deep;
int stack[1002];
int found;
int top;
char act[] = "drul";
typedef struct
{
	int stat[4][4];
	int px;
	int py;
}node_t;
node_t st;
int is_ok(node_t node)
{
	int tmp[10], res, i, j, k = 1;
	for(i = 1;i <= 3; i++) 
		for(j = 1;j <= 3; j++) tmp[k++] = node.stat[i][j];
	res = 0;
	for(i = 1;i <= 9; i++) 
		for(j = 1;j < i; j++) if(tmp[i] < tmp[j]) res++;
	res += 6 - node.px - node.py;
	return (res & 1) == 0;
}
int dist(node_t node)
{
	int res, i, j, k;
	res = 0;
	for(i = 1;i <= 3; i++)
	{
		for(j = 1;j <= 3; j++)
		{
			k = node.stat[i][j] - 1;
			res += ABS(i - goal[k][0]) + ABS(j - goal[k][1]);
		}
	}
	return res;
}
void output()
{
	int i;
	for(i = 1;i <= top; i++) printf("%c", act[stack[i]]);
	printf("\n");
}
void ida_star(node_t cur, int dp, int max_deep)
{
	node_t nxt;
	int f = dist(cur);
	int tx, ty, x, y, t, i;
	if(f + dp > max_deep || found) return;
	if(f == 0)
	{
		output();
		found = 1;
		return;
	}
	x = cur.px; y = cur.py;
	for(i = 0;i < 4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if(tx < 1 || tx > 3 || ty < 1 || ty > 3) continue;
		memcpy(&nxt, &cur, sizeof(cur));
		nxt.stat[x][y] = nxt.stat[tx][ty];
		nxt.stat[tx][ty] = 9;
		nxt.px = tx; nxt.py = ty;
		stack[++top] = i;
		ida_star(nxt, dp + 1, max_deep);
		--top;
	}
}
void init()
{
	int x, y, i;
	char ch;
	ch = getchar();
	i = 0;
	while(ch != '\n')
	{
		if((ch >= '1' && ch <= '9') || ch == 'x')
		{
			x = i / 3 + 1; y = i % 3 + 1; i++;
			if(ch == 'x')
			{
				st.stat[x][y] = 9;
				st.px = x; 
				st.py = y;
			}
			else st.stat[x][y] = ch - '0';
		}
		ch = getchar();
	}
	max_deep = dist(st);
}
int main()
{
	int i;
	init();
	if(is_ok(st) == 0)
	{
		printf("unsolvable\n");
		return 0;
	}
	found = 0;
	while(found == 0)
	{
		top = 0;
		ida_star(st, 0, max_deep);
		max_deep++;
	}
	return 0;
}
