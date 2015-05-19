#include <stdio.h>
#include <string.h>
#define MAXN 1<<20
int act[9][9] = {{1, 1, 0, 1, 1, 0, 0, 0, 0},
				 {1, 1, 1, 0, 0, 0, 0, 0, 0},
				 {0, 1, 1, 0, 1, 1, 0, 0, 0},
				 {1, 0, 0, 1, 0, 0, 1, 0, 0},
				 {0, 1, 0, 1, 1, 1, 0, 1, 0},
				 {0, 0, 1, 0, 0, 1, 0, 0, 1},
				 {0, 0, 0, 1, 1, 0, 1, 1, 0},
				 {0, 0, 0, 0, 0, 0, 1, 1, 1},
				 {0, 0, 0, 0, 1, 1, 0, 1, 1}};
int pre[MAXN][2];
int que[MAXN];
int head, tail, st;
void init()
{
	int i, x;
	st = 0;
	for(i = 1;i <= 9; i++)
	{
		scanf("%d", &x);
		st = (st<<2) | x;
	}
}
void bfs()
{
	int cur, tmp, i, j, k, t;
	memset(pre, -1, sizeof(pre));
	que[0] = st;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		cur = que[head];
		for(i = 1;i <= 9; i++)
		{
			tmp = 0;
			for(j = 1;j <= 9; j++)
			{
				k = (cur>>(18 - j * 2)) & 3;
				t = act[i-1][j-1];
				k = (k + t) - (((k+t)>>2)<<2);
				tmp = (tmp<<2) | k;
			}
			if(pre[tmp][0] == -1)
			{
				pre[tmp][0] = cur;
				pre[tmp][1] = i;
				if(tmp == 0) return;
				que[tail++] = tmp;
			}
		}
		head++;
	}
}
void output()
{
	int i, j;
	i = 0; j = 0;
	while(i != st)
	{
		que[++j] = pre[i][1];
		i = pre[i][0];
	}
	for(i = j;i > 1; i--) printf("%d ", que[i]);
	printf("%d\n", que[1]);
}
int main()
{
	init();
	bfs();
	output();
	return 0;
}

