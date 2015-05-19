#include <stdio.h>
#include <stdlib.h>
#define MAXN 2502
typedef struct
{
	int spf;
	int cap;
}sun_t;
typedef struct
{
	int min;
	int max;
}cow_t;
sun_t sun[MAXN];
cow_t cow[MAXN];
int c, l;
void init()
{
	int i;
	scanf("%d %d", &c, &l);
	for(i = 1;i <= c; i++) scanf("%d %d", &cow[i].min, &cow[i].max);
	for(i = 1;i <= l; i++) scanf("%d %d", &sun[i].spf, &sun[i].cap);
}
int cmp1(const void* p1, const void* p2)
{
	cow_t* a = (cow_t*)p1;
	cow_t* b = (cow_t*)p2;
	return a->max - b->max;
}
int cmp2(const void* p1, const void* p2)
{
	sun_t* a = (sun_t*)p1;
	sun_t* b = (sun_t*)p2;
	return a->spf - b->spf;
}
void solve()
{
	int ans, i, j;
	qsort((void*)&cow[1], c, sizeof(cow[1]), cmp1);
	qsort((void*)&sun[1], l, sizeof(sun[1]), cmp2);
	ans = 0;
	for(i = 1;i <= c; i++)
	{
		for(j = 1;j <= l; j++)
		{
			if(cow[i].min <= sun[j].spf && sun[j].spf <= cow[i].max && sun[j].cap > 0)
			{
				sun[j].cap--;
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
