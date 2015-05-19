#include <stdio.h>
#include <stdlib.h>
#define MAXN 100002
typedef struct
{
	int t;
	int d;
}cow_t;
cow_t cow[MAXN];
int n;
int s;
int cmp(const void* p1, const void* p2)
{
	cow_t a = *(cow_t*)p1;
	cow_t b = *(cow_t*)p2;
	return a.t * b.d - a.d * b.t;
}
void init()
{
	int i;
	scanf("%d", &n);
	s = 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &cow[i].t, &cow[i].d);
		s += cow[i].d;
	}
}
void solve()
{
	long long ans;
	int i;
	qsort((void*)&cow[1], n, sizeof(cow[1]), cmp);
	ans = 0;
	for(i = 1;i <= n; i++)
	{
		s -= cow[i].d;
		ans += 2 * s * cow[i].t;
	}
	printf("%lld\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
