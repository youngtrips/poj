#include <stdio.h>
#include <string.h>
#define F_U(x) ((x)>>4)
#define F_F(x) (((x)&12)>>2)
#define F_R(x) (((x)&3))
#define oo 0x7fffffff
int board[10];
int rev[4] = { 2, 3, 0, 1};
/*
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
*/
int dx[4] = {3, 1, -3, -1};
int goal[10];
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
	int i, j, x, y;
	scanf("%d %d", &y, &x);
	if(x == 0 && y == 0) return 0;
	for(i = 1;i <= 9; i++) board[i] = 27;
	board[0] = (x - 1) * 3 + y;
	board[board[0]] = 0;
	for(i = 1;i <= 9; i++)
	{
		scanf("%s", col);
		if(col[0] == 'W') goal[i] = 1;
		if(col[0] == 'R') goal[i] = 2;
		if(col[0] == 'B') goal[i] = 3;
		if(col[0] == 'E') goal[i] = 0;
	}
	return 1;
}
void mv(int dir)
{
	int tmp, tx, x, u, f, r;
	x = board[0];
	tx = x + dx[dir];
	u = F_U(board[tx]);
	f = F_F(board[tx]);
	r = F_R(board[tx]);
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
	board[x] = tmp;
	board[tx] = 0;
	board[0] = tx;
}
int heur()
{
	int cnt, i, j;
	cnt = 0;
	for(i = 1;i <= 9; i++)
		if(goal[i] != F_U(board[i])) cnt++;
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
	p = board[0];
	for(i = 1;i <= act[p][0]; i++)
	{
		k = act[p][i];
		if((pre == 0 && k == 2) || (pre == 2 && k == 0)) continue;
		if((pre == 1 && k == 3) || (pre == 3 && k == 1)) continue;
		mv(k);
		dfs(k, dp + 1, maxdp);
		mv(rev[k]);
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
