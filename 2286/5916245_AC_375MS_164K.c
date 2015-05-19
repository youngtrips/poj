#include <stdio.h>
#include <string.h>
#define MAXM 26
#define MAXN 8
int col[2][MAXN] = {{0, 1, 3, 7, 12, 16, 21, 23}, {0,  2,  4,  9, 13, 18, 22, 24}};
int row[2][MAXN] = {{0, 5, 6, 7, 8,   9, 10, 11}, {0, 14, 15, 16, 17, 18, 19, 20}};
int center[8] = { 7, 8, 9, 12, 13, 16, 17, 18};
int board[MAXM];
int found;
int top;
int key;
char ans[1000002];
char ops[1000002];
int init()
{
	int i;
	scanf("%d", &board[1]);
	if(board[1] == 0) return 0;
	for(i = 2;i <= 24; i++) scanf("%d", &board[i]);
	return 1;
}
void mv(int board[], int dir)
{
	int tmp, i;
	switch(dir)
	{
	case 0:
		tmp = board[col[0][1]];
		for(i = 1;i < 7; i++) board[col[0][i]] = board[col[0][i+1]];
		board[col[0][7]] = tmp; break;
	case 1:
		tmp = board[col[1][1]];
		for(i = 1;i < 7; i++) board[col[1][i]] = board[col[1][i+1]];
		board[col[1][7]] = tmp; break;
	case 2:
		tmp = board[row[0][7]];
		for(i = 7;i > 1; i--) board[row[0][i]] = board[row[0][i-1]];
		board[row[0][1]] = tmp; break;
	case 3:
		tmp = board[row[1][7]];
		for(i = 7;i > 1; i--) board[row[1][i]] = board[row[1][i-1]];
		board[row[1][1]] = tmp; break;
	case 4:
		tmp = board[col[1][7]];
		for(i = 7;i > 1; i--) board[col[1][i]] = board[col[1][i-1]];
		board[col[1][1]] = tmp; break;
	case 5:
		tmp = board[col[0][7]];
		for(i = 7;i > 1; i--) board[col[0][i]] = board[col[0][i-1]];
		board[col[0][1]] = tmp; break;
	case 6:
		tmp = board[row[1][1]];
		for(i = 1;i < 7; i++) board[row[1][i]] = board[row[1][i+1]];
		board[row[1][7]] = tmp; break;
	case 7:
		tmp = board[row[0][1]];
		for(i = 1;i < 7; i++) board[row[0][i]] = board[row[0][i+1]];
		board[row[0][7]] = tmp; break;
	}
}
int heur(int board[])
{
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int i;
	for(i = 0;i < 8; i++)
	{
		switch(board[center[i]])
		{
		case 1: n1++; break;
		case 2: n2++; break;
		case 3: n3++; break;
		}
	}
	if(n1 < n2) n1 = n2;
	if(n1 < n3) return 8 - n3;
	return 8 - n1;
}
void dfs(int board[], int pre, int dp, int maxdp)
{
	int f = heur(board);
	int tmp[MAXM], i;
	if(f + dp > maxdp || found) return;
	if(f == 0)
	{
		ops[top + 1] = '\0';
		if(found == 0)
		{
			strcpy(ans, ops);
			key = board[12];
			found = 1;
		}
		/*
		else
		{
			if(strcmp(ans, ops) > 0)
			{
				strcpy(ans, ops);
				key = board[12];
			}
		}
		*/
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
		ops[++top] = 'A' + i;
		dfs(tmp, i, dp + 1, maxdp);
		top--;
	}	
}
void ida_star()
{
	int maxdp = heur(board);
	if(maxdp == 0)
	{
		printf("No moves needed\n");
		printf("%d\n", board[12]);
		return;
	}
	found = 0;
	while(found == 0)
	{
		top = -1;
		dfs(board, -1, 0, maxdp);
		maxdp++;
	}
	printf("%s\n", ans);
	printf("%d\n", key);
}
int main()
{
	while(init()) ida_star();
	return 0;
}
