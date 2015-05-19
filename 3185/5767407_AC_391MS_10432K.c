#include <stdio.h>
#include <string.h>
#define MAXM 1<<21
#define MAXN 20
int act[MAXN] = { 3, 7, 14, 28, 56, 112, 224, 448, 896, 1792, 3584, 7168, 14336, 28672, 57344, 114688, 229376, 458752, 917504, 786432 };
int que[MAXM];
int dis[MAXM];
int head, tail;
int st;
void init()
{
	int i, x;
	for(st = 0, i = 1;i <= 20; i++)
	{
		scanf("%d", &x);
		st = st * 2 + x;
	}
}
void bfs()
{
	int i, j, t;
	memset(dis, -1, sizeof(dis));
	dis[st] = 0;
	que[0] = st;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		i = que[head];
		for(j = 0;j < 20; j++)
		{
			t = i ^ act[j];
			if(dis[t] == -1)
			{
				dis[t] = dis[i] + 1;
				if(t == 0) return;
				que[tail++] = t;
			}
		}
		head++;
	}
}
int main()
{
	init();
	bfs();
	printf("%d\n", dis[0]);
	return 0;
}
