#include <stdio.h>
#include <string.h>
#define oo 99999999
#define MAX 202
typedef struct
{
	int x;
	int y;
	int v;
}mat_t;
mat_t nz[MAX * MAX], z[MAX * MAX];
int ans[MAX][MAX], dis[MAX * MAX], t1, t2, n;
void init()
{
	int i, j, k;
	t1 = 0; t2 = 0;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			scanf("%d", &k);
			ans[i][j] = k;
			if(k == 0)
			{
				z[t1].x = i;
				z[t1].y = j;
				z[t1].v = k;
				t1++;
			}
			else
			{
				nz[t2].x = i;
				nz[t2].y = j;
				nz[t2].v = k;
				t2++;
			}
		}
	}
}
int myabs(int x) {return x < 0 ? (-x) : x;}
int dist(int i, int j)
{
	return myabs(z[i].x - nz[j].x) + myabs(z[i].y - nz[j].y);
}
void search()
{
	int min_v, min_d, i, j, d;
	for(i = 0;i < t1; i++)
	{
		memset(dis, 0, sizeof(dis));
		min_d = oo;
		for(j = 0;j < t2; j++)
		{
			d = dist(i, j);
			dis[d]++;
			if(min_d > d){ min_d = d; min_v = nz[j].v;}
		}
		if(min_d != oo)
		{
			if(dis[min_d] == 1) z[i].v = min_v;
		}
		ans[z[i].x][z[i].y] = z[i].v;
	}
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j < n; j++) printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][j]);
	}
}
int main()
{
	init();
	search();
	return 0;
}
