#include <stdio.h>
#define N 100001
int dis[N];
int dx[3] = {-1, 1, 0};
int dy[3] = { 1, 1, 2};
int q[N];
int head, tail, start, end;
void init()
{
	int i;
	for(i = 0;i <= N; i++) dis[i] = -1;
	scanf("%d %d", &start, &end);
	dis[start] = 0;
	q[0] = start;
	tail = 1;
}
void bfs()
{
	int i, x, tmp, k;
	head = 0;
	while(head < tail)
	{
		x = q[head];
		k = dis[x];
		for(i = 0;i < 3; i++)
		{
			tmp = x * dy[i] + dx[i];
			if(tmp >= 0 && tmp < N && dis[tmp] == -1)
			{
				dis[tmp] = k + 1;
				q[tail] = tmp;
				tail++;
			}
			if(tmp == end) return;
		}
		head++;
	}
}
int main()
{
	init();
	bfs();
	printf("%d\n", dis[end]);
	return 0;
}
