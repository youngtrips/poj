#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SQR(x) ((x)*(x))
#define MAX 1002
typedef struct
{
	int l;
	int r;
}range_t;
range_t range[MAX];
int n, d, t = 1;
int cmp(const void* p1, const void* p2)
{
	range_t* a = (range_t*)p1;
	range_t* b = (range_t*)p2;
	return a->l - b->l;
}
int init()
{
	int i, x, y;
	scanf("%d %d", &n, &d);
	if(n == 0 && d == 0) return 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		range[i].l = x - sqrt(SQR(d) - SQR(y));
		range[i].r = x + sqrt(SQR(d) - SQR(y));
	}
	return 1;
}
void solve()
{
	int max;
	int cnt;
	int tmp;
	int i, j;
	if(d <= 0) max = -1;
	else
	{
		qsort((void*)&range[1], n, sizeof(range[1]), cmp);
		tmp = range[1].r;
		max = 0;
		cnt = 1;
		for(i = 2;i <= n; i++)
		{
			if(tmp >= range[i].r) cnt++;
			else cnt = 1;
			tmp = range[i].r;
		}
		if(max < cnt) max = cnt;
	}
	printf("Case %d: %d\n", t++, max == 0 ? -1 : max);
}
int main()
{
	while(init()) solve();
	return 0;
}
