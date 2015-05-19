#include <stdio.h>
#include <string.h>
#define MAX 65536
typedef struct
{
	int x; 
	int y;
	int p;
}path_t;
path_t pre[MAX], ans[MAX];
int dis[MAX], q[MAX], head, tail;
int mask[4][4] = {{63624, 62532, 61986, 61713}, {36744, 20292, 12066, 7953},{35064, 17652, 8946,  4593},{34959, 17487, 8751, 4383}};
void init()
{
	int stat = 0, i, j;
	for(i = 1;i <= 4; i++)
	{
		for(j = 1;j <= 4; j++)
		{
			stat <<= 1;
			if(getchar() == '-') stat++;
		}
		getchar();
	}
	memset(pre, -1, sizeof(pre));
	memset(dis, -1, sizeof(dis));
	dis[stat] = 0;
	q[0] = stat;
	head = 0; 
	tail = 1;
}
void bfs()
{
	int cur, tmp, i, j, k;
	while(head < tail)
	{
		cur = q[head];
		k = dis[cur];
		for(i = 0;i < 4; i++)
			for(j = 0;j < 4; j++)
			{
				tmp = cur ^ mask[i][j];
				if(dis[tmp] == -1)
				{
					pre[tmp].x = i;
					pre[tmp].y = j;
					pre[tmp].p = cur;
					dis[tmp] = k + 1;
					if(tmp == 65535) return;
					q[tail++] = tmp;
				}
			}
		head++;
	}
}
int main()
{
	int i = 65535, j = 0;
	init();
	bfs();
	printf("%d\n", dis[65535]);
	while(pre[i].p != -1)
	{
		ans[j].x = pre[i].x + 1;
		ans[j].y = pre[i].y + 1;
		j++;
		i = pre[i].p;
	}
	for(i = j - 1;i >= 0; i--) printf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}
