#include <stdio.h>
#include <stdlib.h>
#define SQR(x) ((x)*(x))
#define MAX 1002
typedef struct
{
	int x;
	int y;
}point_t;
point_t island[MAX];
int n, d, t = 1;
int cmp(const void* p1, const void* p2)
{
	point_t* a = (point_t*)p1;
	point_t* b = (point_t*)p2;
	return b->y - a->y;
}
int init()
{
	int i, x, y;
	scanf("%d %d", &n, &d);
	if(n == 0 && d == 0) return 0;
	for(i = 1;i <= n; i++) scanf("%d %d", &island[i].x, &island[i].y);
	return 1;
}
void solve()
{
	int max;
	int cnt;
	int dd, i, j, x, y;
	qsort((void*)&island[1], n, sizeof(island[1]), cmp);
	dd = SQR(d);
	max = 0;
	for(i = 1;i <= n; i++)
	{
		if(island[i].y <= d)
		{
			x = island[i].x; y = 0;
			cnt = 0;
			for(j = 1;j <= n; j++)
				if(SQR(x - island[j].x) + SQR(y - island[j].y) <= dd) cnt++;
			if(max < cnt) max = cnt;
		}
	}
	printf("Case %d: %d\n", t++, max == 0 ? -1 : max);
}
int main()
{
	while(init()) solve();
	return 0;
}
