#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAXN 1000002
int px[24][2] = {
								{1, 3}, 		{1, 5},
								{2, 3}, 		{2, 5},
				{3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7},
								{4, 3},			{4, 5},
				{5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7},
								{6, 3},			{6, 5},
								{7, 3},			{7, 5}
				};
char stack[MAXN];
int board[8][8];
int found;
int top;
int init()
{
	int i, k;
	memset(board, 0, sizeof(board));
	for(i = 0;i < 24; i++)
	{
		scanf("%d", &k);
		if(k == 0) return 0;
		board[px[i][0]][px[i][1]] = k;
	}
	return 1;
}
void mv(int board[][8], int dir)
{
	int tmp, i;
	if(dir == 0)
	{
		tmp = board[1][3];
		for(i = 1;i < 7; i++) board[i][3] = board[i+1][3];
		board[7][3] = tmp;
	}
	if(dir == 1)
	{
		tmp = board[1][5];
		for(i = 1;i < 7; i++) board[i][5] = board[i+1][5];
		board[7][5] = tmp;
	}
	if(dir == 2)
	{
		tmp = board[3][7];
		for(i = 7;i > 1; i--) board[3][i] = board[3][i-1];
		board[3][1] = tmp;
	}
	if(dir == 3)
	{
		tmp = board[5][7];
		for(i = 7;i > 1; i--) board[5][i] = board[5][i-1];
		board[5][1] = tmp;
	}
	if(dir == 4)
	{
		tmp = board[7][5];
		for(i = 7;i > 1; i--) board[i][5] = board[i-1][5];
		board[1][5] = tmp;
	}
	if(dir == 5)
	{
		tmp = board[7][3];
		for(i = 7;i > 1; i--) board[i][3] = board[i-1][3];
		board[1][3] = tmp;
	}
	if(dir == 6)
	{
		tmp = board[5][1];
		for(i = 1;i < 7; i++) board[5][i] = board[5][i+1];
		board[5][7] = tmp;
	}
	if(dir == 7)
	{
		tmp = board[3][1];
		for(i = 1;i < 7; i++) board[3][i] = board[3][i+1];
		board[3][7] = tmp;
	}
}
int heur(int board[][8])
{
	int n1 = 0;
	int n2 = 0;
   	int n3 = 0;
	int i, j;
	for(i = 3;i <= 5; i++)
		for(j = 3;j <= 5; j++)
		{
			if(i == 4 && j == 4) continue;
			n1 += (board[i][j] == 1);
			n2 += (board[i][j] == 2);
			n3 += (board[i][j] == 3);
		}
	if(n1 < n2) n1 = n2;
	return 8 - (n1 > n3 ? n1 : n3);
}
void dfs(int board[][8], int dp, int maxdp, int pre)
{
	int tmp[8][8];
	int f = heur(board);
	int i;
	if(f + dp > maxdp || found) return;
	if(f == 0)
	{
		found = 1;
		assert(top + 1 < MAXN);
		stack[++top] = '\0';
		printf("%s\n", stack);
		printf("%d\n", board[3][3]);
		return;
	}
	for(i = 0;i < 8; i++)
	{
		if((pre == 0 && i == 5) || (pre == 5 && i == 0)) continue;
		if((pre == 1 && i == 4) || (pre == 4 && i == 1)) continue;
		if((pre == 2 && i == 7) || (pre == 7 && i == 2)) continue;
		if((pre == 3 && i == 6) || (pre == 6 && i == 3)) continue;
		memcpy(tmp, board, sizeof(tmp));
		mv(tmp, i);
		assert(top + 1 < MAXN);
		stack[++top] = 'A' + i;
		dfs(tmp, dp + 1, maxdp, i);
		top--;
	}
}
void ida_star()
{
	int maxdp = heur(board);
	if(maxdp == 0)
	{
		printf("No moves needed\n");
		return;
	}
	found = 0;
	while(found == 0)
	{
		top = -1;
		dfs(board, 0, maxdp, -1);
		maxdp++;
	}
}
int main()
{
	while(init()) ida_star();
	return 0;
}
