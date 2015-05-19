#include <stdio.h>
#include <stdlib.h>
#define MAXN 1002
typedef struct
{
	int x; int y; int s;
}dat_t;
dat_t sum[MAXN * MAXN];
dat_t dif[MAXN * MAXN];
int set[MAXN];
int tot, n;
int cmp(const void* p1, const void* p2)
{
	dat_t* a = (dat_t*)p1;
	dat_t* b = (dat_t*)p2;
	return a->s - b->s;
}
int init()
{
	int i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
	for(i = 1;i <= n; i++) scanf("%d", &set[i]);
	tot = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = i + 1;j <= n; j++)
		{
			++tot;
			sum[tot].x = set[i]; sum[tot].y = set[j]; sum[tot].s = set[i] + set[j];
			dif[tot].x = set[i] > set[j] ? set[i] : set[j];
			dif[tot].y = set[i] < set[j] ? set[i] : set[j];
			dif[tot].s = dif[tot].x - dif[tot].y;
		}
	}
	qsort((void*)&sum[1], tot, sizeof(sum[1]), cmp);
	qsort((void*)&dif[1], tot, sizeof(dif[1]), cmp);
	return 1;
}
void solve()
{
	int ans, i, j;
	i = 1; j = 1;
	ans = -0x7fffffff;
	while(i <= tot && j <= tot)
	{
		if(sum[i].s > dif[j].s) j++;
		if(sum[i].s < dif[j].s) i++;
		if(sum[i].s == dif[j].s)
		{
			if(sum[i].x != dif[j].x && sum[i].x != dif[j].y &&
			   sum[i].y != dif[j].x && sum[i].y != dif[j].y)
			{
				if(ans < dif[j].x) ans = dif[j].x;
			}
			i++; j++;
		}
	}
	if(ans == -0x7fffffff) printf("no solution\n");
	else printf("%d\n", ans);
}
int main()
{
	while(init()) solve();
	return 0;
}
