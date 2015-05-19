#include <stdio.h>
#include <string.h>
#define F_U(x) ((x)>>4)
#define F_F(x) (((x)&12)>>2)
#define F_R(x) (((x)&3))
#define oo 0x7fffffff
typedef struct
{
	int board[4][4];
	int x; int y;
}node_t;
node_t start;
int rev[4] = { 2, 3, 0, 1};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int goal[4][4];
int act[10][5] = {{0},
				  {/*1*/ 2, 0, 1},
				  {/*2*/ 3, 0, 1, 3},
				  {/*3*/ 2, 0, 3},
				  {/*4*/ 3, 0, 1, 2},
				  {/*5*/ 4, 0, 1, 2, 3},
				  {/*6*/ 3, 0, 2, 3},
				  {/*7*/ 2, 1, 2},
				  {/*8*/ 3, 1, 2, 3},
				  {/*9*/ 2, 2, 3}};
int found;
int min;
int init()
{
	char col[2];
	int i, j;
	scanf("%d %d", &start.y, &start.x);
	if(start.x == 0 && start.y == 0) return 0;
	for(i = 1;i <= 3; i++)
		for(j = 1;j <= 3; j++) start.board[i][j] = 27;
	start.board[start.x][start.y] = 0;
	for(i = 1;i <= 3; i++)
	{
		for(j = 1;j <= 3; j++)
		{
			scanf("%s", col);
			if(col[0] == 'W') goal[i][j] = 1;
			if(col[0] == 'R') goal[i][j] = 2;
			if(col[0] == 'B') goal[i][j] = 3;
			if(col[0] == 'E') goal[i][j] = 0;
		}
	}
	return 1;
}
void mv(node_t* start, int dir)
{
	int tmp, tx, ty, x, y, u, f, r;
	x = start->x; y = start->y;
	tx = x + dx[dir];
	ty = y + dy[dir];
	u = F_U(start->board[tx][ty]);
	f = F_F(start->board[tx][ty]);
	r = F_R(start->board[tx][ty]);
	switch(dir)
	{
	case 0: /* empty to down */
		tmp = (f<<4) | (u<<2) | r;
		break;
	case 1:
		tmp = (r<<4) | (f<<2) | u;
		break;
	case 2:
		tmp = (f<<4) | (u<<2) | r;
		break;
	case 3:
		tmp = (r<<4) | (f<<2) | u;
		break;
	}
	start->board[x][y] = tmp;
	start->board[tx][ty] = 0;
	start->x = tx; start->y = ty;
}
int heur()
{
	int cnt, i, j;
	cnt = 0;
	for(i = 1;i <= 3; i++)
		for(j = 1;j <= 3; j++) if(goal[i][j] != F_U(start.board[i][j])) cnt++;
	return cnt;
}
void dfs(int pre, int dp, int maxdp)
{
	int f = heur();
	int i, p, k;
	if(dp > 31) found = 2;
	if(min > f) min = f;
	if(f + dp > maxdp || found) return;
	if(f == 0)
	{
		printf("%d\n", dp);
		found = 1;
		return;
	}
	p = (start.x - 1) * 3 + start.y;
	for(i = 1;i <= act[p][0]; i++)
	{
		k = act[p][i];
		if((pre == 0 && k == 2) || (pre == 2 && k == 0)) continue;
		if((pre == 1 && k == 3) || (pre == 3 && k == 1)) continue;
		mv(&start, k);
		dfs(k, dp + 1, maxdp);
		mv(&start, rev[k]);
	}
}
void ida_start()
{
	int maxdp = heur();
	found = 0;
	while(found == 0)
	{
		min = oo;
		dfs(-1, 0, maxdp);
		maxdp += min;
	}
}
int main()
{
	while(init())
	{
		ida_start();
		if(found == 2) printf("-1\n");
	}
	return 0;
}
