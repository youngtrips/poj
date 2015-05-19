#include <stdio.h>
#include <string.h>
int dis[65536], q[65536], head, tail;
int mask[16] = {51200, 58368, 29184, 12544, 35968, 20032, 10016, 4880, 2248, 1252, 626, 305, 140, 78, 39, 19};
void init()
{
	char ch;
	int stat = 0, i, j, k;
	for(i = 1;i <= 4; i++)
	{
		for(j = 1;j <= 4; j++)
		{
			ch = getchar();
			if(ch == 'b') k = 1;
			else k = 0;
			stat = stat * 2 + k;
		}
		getchar();
	}
	memset(dis, -1, sizeof(dis));
	q[0] = stat;
	head = 0;
	tail = 1;
	dis[stat] = 0;
}
int bfs()
{
	int cur, tmp, i, k;
	if(q[0] == 0 || q[0] == 65535) return 0;
	while(head < tail)
	{
		cur = q[head];
		k = dis[cur];
		for(i = 0;i < 16; i++)
		{
			tmp = cur ^ mask[i];
			if(dis[tmp] == -1)
			{
				dis[tmp] = k + 1;
				if(tmp == 0 || tmp == 65535) return k + 1;
				q[tail++] = tmp;
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	int res;
	init();
	res = bfs();
	if(res == -1) printf("Impossible\n");
	else printf("%d\n", res);
	return 0;
}
