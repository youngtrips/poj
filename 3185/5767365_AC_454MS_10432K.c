#include <stdio.h>
#include <string.h>
#define MAXM 1<<21
#define MAXN 20
int que[MAXM];
int dis[MAXM];
int act[MAXN];
int head, tail;
int st;
void preprocess()
{
	int i;
	for(i = 19;i >= 0; i--)
	{
		act[i] = 1<<i;
		if(i < 19) act[i] |= (1<<(i+1));
		if(i > 0) act[i] |= (1<<(i-1));
	}
}
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
	preprocess();
	init();
	bfs();
	printf("%d\n", dis[0]);
	return 0;
}
