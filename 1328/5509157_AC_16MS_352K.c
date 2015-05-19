#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 1e-20
#define SQR(x) ((x)*(x))
#define MAX 1002
typedef struct
{
	double l;
	double r;
}range_t;
range_t range[MAX];
int flag, n, d, t = 1;
int cmp(const void* p1, const void* p2)
{
	range_t* a = (range_t*)p1;
	range_t* b = (range_t*)p2;
	double tmp = a->l - b->l;
	if(fabs(tmp) < eps)
	{
		tmp = b->r - a->r;
		if(tmp > 0) return 1;
		else return -1;
	}
	else if(tmp > 0) return 1;
	else return -1;
}
int init()
{
	int i, x, y;
	scanf("%d %d", &n, &d);
	if(n == 0 && d == 0) return 0;
	flag = 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		if(y > d) flag = 1;
		if(flag == 0)
		{
			range[i].l = x * 1.0 - sqrt(SQR(d * 1.0) - SQR(y * 1.0));
			range[i].r = x * 1.0 + sqrt(SQR(d) - SQR(y));
		}
	}
	return 1;
}
void solve()
{
	double cur;
	int cnt, i, j;
	if(flag) cnt = -1;
	else
	{
		qsort((void*)&range[1], n, sizeof(range[1]), cmp);
		cur = range[1].r;
		cnt = 1;
		for(i = 2;i <= n; i++)
		{
			if(range[i].l > cur + eps) { cnt++; cur = range[i].r;}
			else if(range[i].r + eps < cur) cur = range[i].r;
		}
	}
	printf("Case %d: %d\n", t++, cnt);
}
int main()
{
	while(init()) solve();
	return 0;
}
